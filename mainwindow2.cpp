#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainwindow2.h"
#include "ui_mainwindow2.h"

#include "mainwindow1_2.h"
#include "ui_mainwindow1_2.h"

#include "tmpwindow.h"
#include "ui_tmpwindow.h"

#include "hint.h"
#include "ui_hint.h"

#include <QKeyEvent>
#include <QtWidgets>
#include <random>
#include <iostream>
#include <QPainter>
#include <QFile>
#include <fstream>

void MainWindow2::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(QColor(255,0,0));
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawLine(QPoint(pposx,pposy),QPoint(pposx2,pposy2));
} //使用arrow时的动画，起点射向终点的一条红线

using std::mt19937;
mt19937 Rand(time(0));
const int SHOWWPH=50,SHOWWPW=200,SHOWWPX=1000,SHOWWPY=0; //每个武器显示的高度,宽度,x坐标，y坐标
MainWindow2::MainWindow2(std::string usrname,int level,int read_mode,QWidget *parent)://read_mode表示是否为读档创建
    QMainWindow(parent),
    wphl(nullptr), //当前选择武器高亮(WeaPon HighLight)
    cmp{}, //按位置存储生物
    mode(0), //mode表示当前进行的行动：0:移动，-1:选择武器，1~n:为发射武器，mode选择目标
    mx(0),
    my(0), //mx,my:目标指示器，当前所在位置
    lvl(level),
    usrname(usrname),
    ui(new Ui::MainWindow2)
{
    setMouseTracking(true);//此处不加会导致鼠标在其上时不按鼠标按键时不追踪鼠标移动
    ui->setupUi(this);
    connect(ui->actionQuit,&QAction::triggered,this,&MainWindow2::Back); //退出按钮
    connect(ui->actionPause,&QAction::triggered,this,&MainWindow2::option); //弹出tmpwindow
    connect(ui->actionHints,&QAction::triggered,this,&MainWindow2::hint); //弹出提示框

    ui->actionHints->setIcon(QIcon(":/new/prefix1/question.png")); //菜单栏设置图标
    ui->actionPause->setIcon(QIcon(":/new/prefix1/pause.png"));
    ui->actionQuit->setIcon(QIcon(":/new/prefix1/exit.png"));

    setWindowTitle(QString::fromStdString("Level "+std::to_string(lvl)));

    CCreature * u=new CCreature(0,0,0,10+lvl/2,4+lvl/2,ui->centralwidget,":/new/prefix1/me.png"); //自己，图源网络
    u->atk.push_back(Attack(0,3+(lvl+1)/3,std::min(5,3+(lvl+2)/5),"Shoot",1));
    u->atk.push_back(Attack(1,2+(lvl+2)/3,std::min(6,4+lvl/5),"Bomb",3));
    u->atk.push_back(Attack(2,3+lvl/3,std::min(7,5+lvl/4),"Arrow",2)); //赋予武器
    plax=&(u->posx),play=&(u->posy);
    self=u;
    clist.push_back(u);
    cmp[0][0]=u;
    if(!read_mode){ //如果不是读档，即是新游戏
        for(int i=0;i<std::min(lvl*2/3+3,20);i++){ //生成level*2/3+3个敌人,最多20个
            int px=Rand()%XMX,py=Rand()%YMX;
            while(cmp[px][py])px=Rand()%XMX,py=Rand()%YMX; //随机生成敌人位置
            CCreature * u=new CCreature(1,px,py,5+lvl,2+lvl/2,ui->centralwidget,":/new/prefix1/Enemy.png"); //图源网络
            clist.push_back(u);
            cmp[px][py]=u;
        }
    }
    sta=new QLabel(ui->centralwidget);//显示玩家状态
    sta->setGeometry(SHOWWPX,SHOWWPY,SHOWWPW,SHOWWPH);
    sta->show();
    if(!read_mode) UpdWpList();
}

template<typename T>
void MainWindow2::trace(int fx,int fy,int tx,int ty,T act){
    int cx=fx,cy=fy;
    int di=std::min(abs(tx-cx),abs(cy-ty)),ort=std::max(abs(tx-cx),abs(cy-ty))-di;//di(agonal):走对角次数 ort(hogonal):走上下左右次数
    int cnt=0;//原理：设需要走di次斜线和ort次上下左右，cnt>0时走上下左右，cnt<=0时走斜线，每次走斜线+ort,走上下左右-di,保证近似于直线
    while(getDir(cx,cy,tx,ty)!=N){
        int cd=getDir(cx,cy,tx,ty);//当前方向
        if(cd<=3||cd==N){//只走上下左右可以到达
            cx+=dx[cd],cy+=dy[cd];
        }
        else{
            int ndi=std::min(abs(tx-cx),abs(cy-ty));
            int ox=cx+ndi*dx[cd],oy=cy+ndi*dy[cd],odi=getDir(ox,oy,tx,ty);//上下左右走完，剩余需走方向
            if(odi==N)cx+=dx[cd],cy+=dy[cd];//只走对角可以到达
            else{
                if(cnt<=0)cx+=dx[cd],cy+=dy[cd],cnt+=ort;
                else cx+=dx[odi],cy+=dy[odi],cnt-=di;
            }
        }
        act(cx,cy);
    }
}
void MainWindow2::UpdWpList(int ch){
    for(int i=0;i<showwp.size();i++)delete showwp[i];
    showwp.clear();
    for(auto &x:showava)delete x;
    showava.clear();
    if(wphl)delete wphl,wphl=nullptr; //清除原有显示
    sta->setText(QString::fromStdString("HP:"+std::to_string(self->hp)+"/"+std::to_string(self->mhp)+" mATK:"+std::to_string(self->mAtk)));
    if(ch==-1){
        for(int i=0;i<self->atk.size();i++){
            if(!self->atk[i].curcd){
                auto tmp=new QLabel(ui->centralwidget); //指示可选攻击
                tmp->setGeometry(SHOWWPX,SHOWWPY+SHOWWPH*(i+1),SHOWWPW,SHOWWPH);
                tmp->setStyleSheet("background-color: rgba(127, 127, 127, 20);"); //灰色
                tmp->show();
                showava.push_back(tmp);
            }
        }
    }
    for(int i=0;i<self->atk.size();i++){
        auto nlabel=new QLabel(ui->centralwidget);
        nlabel->setGeometry(SHOWWPX,SHOWWPY+SHOWWPH*(i+1),SHOWWPW,SHOWWPH);
        auto txt=std::to_string(i+1)+" "+self->atk[i].name+" ATK:"+std::to_string(self->atk[i].atk)+" R:"+std::to_string(self->atk[i].r)+" CD:"+std::to_string(self->atk[i].curcd)+"/"+std::to_string(self->atk[i].cd-1);
        nlabel->setText(QString::fromStdString(txt));
        nlabel->show();
        showwp.push_back(nlabel); //显示当前拥有武器
        if(i==ch-1){
            wphl=new QLabel(ui->centralwidget); //指示当前选中攻击
            wphl->setGeometry(SHOWWPX,SHOWWPY+SHOWWPH*(i+1),SHOWWPW,SHOWWPH);
            wphl->setStyleSheet("background-color: rgba(0, 0, 255, 20);"); //蓝色
            wphl->show();
        }
    }
}
void MainWindow2::Back(){
    MainWindow1_2 * w=new MainWindow1_2(this->usrname);
    w->show();
    delete this;
}
void MainWindow2::levelUp(){
    MainWindow2 * w=new MainWindow2(this->usrname,lvl+1);
    w->show();
    delete this;
}
bool MainWindow2::checkDie(int nx,int ny){
    if(cmp[nx][ny]->hp<=0){ //如死亡则删除
        auto dd=cmp[nx][ny];
        delete dd;
        for(int i=0;i<clist.size();i++)
            if(dd==clist[i]){
                clist.erase(clist.begin()+i);
                break;
            }
        cmp[nx][ny]=nullptr;
        return true;
    }
    return false;
}
bool MainWindow2::checkDie(CCreature * & tar){
    if(tar->hp<=0){ //如死亡则删除
        delete tar;
        for(int i=0;i<clist.size();i++)
            if(tar==clist[i]){
                clist.erase(clist.begin()+i);
                break;
            }
        tar=nullptr;
        return true;
    }
    return false;
}
void MainWindow2::Move(int dir){
    if(dir==N){ //原地不动
        Upd_All();return;
    }
    int bx=self->posx,by=self->posy;
    int nx=bx+dx[dir],ny=by+dy[dir];
    if(!In(nx,ny))return;
    if(cmp[nx][ny]){ //移动目标有敌人则近身攻击
        self->Attack(cmp[nx][ny]);
        checkDie(nx,ny);
    } //否则移动
    else{
        self->Move(nx,ny);
        cmp[nx][ny]=cmp[bx][by];
        cmp[bx][by]=nullptr;
    }

    Upd_All();
}
void MainWindow2::rAtk(CCreature * & src,int tx,int ty,Attack & A){
    A.curcd=A.cd;
    for(int i=0;i<XMX;i++)
        for(int j=0;j<YMX;j++){
            if(cmp[i][j]&&cmp[i][j]->id==1&&A.InRange(i,j,tx,ty)){
                A.hit(cmp[i][j]);
                checkDie(i,j);
            }
        }
    if(!Upd_All()){
        for(auto &x:showaoe)delete x;
        showaoe.clear();
        mode=0;
        for(auto &x:showr)delete x;
        showr.clear();
    }


}
void MainWindow2::Upd_E(){
    for(int i=1;i<clist.size();i++){
        int bx=clist[i]->posx,by=clist[i]->posy;
        int nd=clist[i]->FindPath(cmp);
        int nx=bx+dx[nd],ny=by+dy[nd];
        if(cmp[nx][ny]){
            if(cmp[nx][ny]->id==0)
            clist[i]->Attack(cmp[nx][ny]);
            continue;
        }
        clist[i]->Move(nx,ny);
        cmp[nx][ny]=cmp[bx][by];
        cmp[bx][by]=nullptr;
    }
}
bool MainWindow2::Upd_All(){
    Upd_E();
    for(auto &x:self->atk)if(x.curcd)--x.curcd;//冷却时间更新
    UpdWpList();
    for(int i=0;i<clist.size();i++)clist[i]->upd();
    if(clist.size()==1){//敌人全部死亡，成功
        QMessageBox::warning(this, tr("Congratulations! You win. Level up!"), tr("Congratulations! You win. Level up!"));
        levelUp();
        return true;
    }
    if(self->hp<=0){//玩家血量<=0，失败
        QMessageBox::warning( this, tr("I am sorry, you fail."), tr("I am sorry, you fail."));
        Back();
        return true;
    }
    return false;
}
void MainWindow2::createShowaoe(int x,int y,Attack atk){
    for(auto &x:showaoe)delete x;
    showaoe.clear();
    for(int i=0;i<XMX;i++)
        for(int j=0;j<YMX;j++){
            if(atk.InRange(i,j,x,y)){
                auto cur=new QLabel(ui->centralwidget);
                cur->setGeometry(i*TSizeX,j*TSizeY,50,50);
                cur->setStyleSheet("background-color: rgba(255, 0, 0, 20);");//红色
                cur->setMouseTracking(true);
                cur->show();
                showaoe.push_back(cur);
            }
        }
}
void MainWindow2::keyPressEvent(QKeyEvent *k){
    if(mode==0){
        switch(k->key()){
            case Qt::Key_Up:Move(U);break;
            case Qt::Key_Down:Move(D);break;
            case Qt::Key_Left:Move(L);break;
            case Qt::Key_Right:Move(R);break;
            case Qt::Key_Y:Move(LU);break;
            case Qt::Key_U:Move(RU);break;
            case Qt::Key_B:Move(LD);break;
            case Qt::Key_N:Move(RD);break;
            case Qt::Key_Space:Move(N);break;
            case Qt::Key_F:mode=-1;UpdWpList(-1);break;
        }
    }
    else
    if(mode==-1){
        int ch=0;
        switch(k->key()){
        case Qt::Key_1:ch=1;break;
        case Qt::Key_2:ch=2;break;
        case Qt::Key_3:ch=3;break;
        case Qt::Key_Escape:ch=-1;break;
        }
           if(ch>=0){
               if(self->atk[ch-1].curcd>0){//选取的武器正在冷却
                   QMessageBox::warning(this, tr("Weapon in cooldown"), tr(("You cannot use the weapon "+self->atk[ch-1].name+" now. It is still in cooldown.").c_str()));
                   mode=0;UpdWpList();
               }
               else{
                   mode=ch;
                   UpdWpList(mode);
                   for(int i=0;i<XMX;i++)
                        for(int j=0;j<YMX;j++){
                            if(InRange(i,j,self->atk[mode-1].r)){//显示范围
                                auto aim2=new QLabel(ui->centralwidget);
                                aim2->setGeometry(i*TSizeX,j*TSizeY,50,50);
                                aim2->setStyleSheet("background-color: rgba(0, 0, 255, 10);");//更浅的蓝色
                                aim2->setMouseTracking(true);
                                aim2->show();
                                showr.push_back(aim2);
                            }
                        }
                   if(InRange(mx,my,self->atk[mode-1].r)){
                       createShowaoe(mx,my,self->atk[mode-1]);
                   }
               }

            }
            else{
                mode=0;UpdWpList();
            }

        }
    else
    if(mode>0){
        switch(k->key()){
            case Qt::Key_Escape:
            UpdWpList();
            for(auto &x:showaoe)delete x;
            showaoe.clear();
            mode=0;
            for(auto &x:showr)delete x;
            showr.clear();
            break;
        }
    }
}
void MainWindow2::mouseMoveEvent(QMouseEvent *k){
    int nx=k->pos().x()/TSizeX,ny=(k->pos().y()-22)/TSizeY;//22为上方选项栏高度，鼠标坐标计算方法和控件坐标略有不同
    if((ny!=my||nx!=mx)){
        mx=nx,my=ny;
        if(mode<=0)return;
        if(InRange(nx,ny,self->atk[mode-1].r)){
            createShowaoe(nx,ny,self->atk[mode-1]);
        }
        else {
            for(auto &x:showaoe)x->hide();

        }
    }
}
void MainWindow2::mousePressEvent(QMouseEvent *k){
    if(mode<=0)return;
    if(k->button()==Qt::LeftButton){
        int nx=k->pos().x()/TSizeX,ny=(k->pos().y()-22)/TSizeY;
        if(InRange(nx,ny,self->atk[mode-1].r,*plax,*play)){
            rAtk(self,nx,ny,self->atk[mode-1]);
        }
    }

}
MainWindow2::~MainWindow2()
{
    for(auto &x:clist)delete x;
    for(auto &x:showr)delete x;
    for(auto &x:showwp)delete x;
    for(auto &x:showaoe)delete x;
	for(auto &x:showava)delete x;
    delete sta;
    delete wphl;
    delete ui;
}

void MainWindow2::option()
{
    TmpWindow *twindow = new TmpWindow(nullptr,this);
    twindow->show();
} //点击pause，弹出中转界面

void MainWindow2::hint()
{
    Hint *hin = new Hint;
    hin->show();
}

bool MainWindow2::save_archive(int num){
    // 写文件
    if (num==1){
        std::ifstream inFile((usrname+"_saving1.txt").c_str(),std::ios::in);
        if(inFile.is_open()){
            inFile.close();
            return false;
        } else {
            std::ofstream outFile((usrname+"_saving1.txt").c_str(),std::ios::out);
            outFile<<lvl<<std::endl;
            outFile<<self->id<<" "<<self->posx<<" "<<self->posy<<" "<<self->mhp<<" "
                                  <<self->hp<<" "<<self->mAtk<<std::endl;
            outFile<<self->atk[0].curcd<<" "<<self->atk[1].curcd<<" "<<self->atk[2].curcd<<std::endl;
            outFile<<clist.size()<<std::endl;
            for(int i=1;i<clist.size();i++){
                outFile<<clist[i]->id<<" "<<clist[i]->posx<<" "<<clist[i]->posy<<" "<<clist[i]->mhp<<" "
                      <<clist[i]->hp<<" "<<clist[i]->mAtk<<std::endl;
            }

//           for(int i=0;i<TSizeX;i++){
//                for(int j=0;j<TSizeY;j++){
//                    if(!cmp[i][j]){
//                        outFile<<0<<std::endl;
//                        continue;
//                    }
//                    outFile<<1<<" "<<cmp[i][j]->id<<" "<<cmp[i][j]->posx<<" "<<cmp[i][j]->posy<<" "<<cmp[i][j]->mhp<<" "
//                          <<cmp[i][j]->hp<<" "<<cmp[i][j]->mAtk<<std::endl;
//                }
//            }
            outFile<<mode<<" "<<mx<<" "<<my<<std::endl;
            outFile.close();
            return true;
        }
    } else if(num==2){
        std::ifstream inFile((usrname+"_saving2.txt").c_str(),std::ios::in);
        if(inFile.is_open()){
            inFile.close();
            return false;
        } else {
            std::ofstream outFile((usrname+"_saving2.txt").c_str(),std::ios::out);
            outFile<<lvl<<std::endl;
            outFile<<self->id<<" "<<self->posx<<" "<<self->posy<<" "<<self->mhp<<" "
                                  <<self->hp<<" "<<self->mAtk<<std::endl;
            outFile<<self->atk[0].curcd<<" "<<self->atk[1].curcd<<" "<<self->atk[2].curcd<<std::endl;
            outFile<<clist.size()<<std::endl;
            for(int i=1;i<clist.size();i++){
                outFile<<clist[i]->id<<" "<<clist[i]->posx<<" "<<clist[i]->posy<<" "<<clist[i]->mhp<<" "
                      <<clist[i]->hp<<" "<<clist[i]->mAtk<<std::endl;
            }

//           for(int i=0;i<TSizeX;i++){
//                for(int j=0;j<TSizeY;j++){
//                    if(!cmp[i][j]){
//                        outFile<<0<<std::endl;
//                        continue;
//                    }
//                    outFile<<1<<" "<<cmp[i][j]->id<<" "<<cmp[i][j]->posx<<" "<<cmp[i][j]->posy<<" "<<cmp[i][j]->mhp<<" "
//                          <<cmp[i][j]->hp<<" "<<cmp[i][j]->mAtk<<std::endl;
//                }
//            }
            outFile<<mode<<" "<<mx<<" "<<my<<std::endl;
            outFile.close();
            return true;
        }
    }else {
        return false;
    }
    return false;
}

/* 存储格式：.txt
 * row0: lvl
 * row1: self ( in sequence: int Id,int px,int py,int mhp,int hp,int mATK )
 * row2: curcd of each weapon ( now only "me" have that )
 * row3: size of clist - n
 * row4-(n+2): a creature in clist per row EXCEPT SELF ( in sequence: int Id,int px,int py,int mhp,int hp,int mATK )
 * row(n+3): mode, mx, myin sequence
 * !!!different numbers in one row will be separated by a whitespace
 */
