#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QKeyEvent>
#include <QtWidgets>
#include <random>
#include <iostream>
using std::mt19937;
mt19937 Rand(time(0));
const int SHOWWPH=50;//每个武器显示的高度
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    wphl(nullptr),
    cmp{},
    mode(0),
    mx(0),
    my(0),
    ui(new Ui::MainWindow2)
{
    setMouseTracking(true);//此处不加会导致鼠标在其上时不按鼠标按键时不追踪鼠标移动
    ui->setupUi(this);
    connect(ui->actionQuit,&QAction::triggered,this,&MainWindow2::Back);//退出按钮
    CCreature * u=new CCreature(0,0,0,10,4,ui->centralwidget,"D:\\cpp\\qt\\untitled\\bot.png");//自己
    u->atk.push_back(Attack(0,3,3,"Shoot"));
    u->atk.push_back(Attack(1,2,4,"Bomb"));
    u->atk.push_back(Attack(2,2,5,"Arrow"));
    plax=&(u->posx),play=&(u->posy);
    self=u;
    clist.push_back(u);
    cmp[0][0]=u;
    for(int i=0;i<7;i++){//生成7个敌人
        int px=Rand()%XMX,py=Rand()%YMX;
        while(cmp[px][py])px=Rand()%XMX,py=Rand()%YMX;
        CCreature * u=new CCreature(1,px,py,6,2,ui->centralwidget,"D:\\cpp\\qt\\untitled\\man.png");
        clist.push_back(u);
        cmp[px][py]=u;
    }
    UpdWpList();
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
    if(wphl)delete wphl,wphl=nullptr;//清除原有显示
    if(ch==-1){
        wphl=new QLabel(ui->centralwidget);//指示可选攻击
        wphl->setGeometry(1000,0,200,SHOWWPH*self->atk.size());
        wphl->setStyleSheet("background-color: rgba(127, 127, 127, 20);");//灰色
        wphl->show();
    }
    for(int i=0;i<self->atk.size();i++){
        auto nlabel=new QLabel(ui->centralwidget);
        nlabel->setGeometry(1000,SHOWWPH*i,200,SHOWWPH);
        nlabel->setText(QString::fromStdString(std::to_string(i+1)+" "+self->atk[i].name));
        nlabel->show();
        showwp.push_back(nlabel);//显示当前可用武器
        if(i==ch-1){
            wphl=new QLabel(ui->centralwidget);//指示当前选中攻击
            wphl->setGeometry(1000,50*i,200,50);
            wphl->setStyleSheet("background-color: rgba(0, 0, 255, 20);");//蓝色
            wphl->show();
        }
    }
}
void MainWindow2::Back(){
    MainWindow * w=new MainWindow;
    w->show();
    delete this;
}
bool MainWindow2::checkDie(int nx,int ny){
    if(cmp[nx][ny]->hp<=0){//如死亡则删除
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
    if(tar->hp<=0){//如死亡则删除
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
    if(dir==N){//原地不动
        Upd_All();return;
    }
    int bx=self->posx,by=self->posy;
    int nx=bx+dx[dir],ny=by+dy[dir];
    if(!In(nx,ny))return;
    if(cmp[nx][ny]){//移动目标有敌人则近身攻击
        self->Attack(cmp[nx][ny]);
        checkDie(nx,ny);
    }//否则移动
    else{
        self->Move(nx,ny);
        cmp[nx][ny]=cmp[bx][by];
        cmp[bx][by]=nullptr;
    }

    Upd_All();
}
void MainWindow2::rAtk(CCreature * & src,int tx,int ty,Attack A){
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
        int nd=clist[i]->FindPath();
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
    UpdWpList();
    for(int i=0;i<clist.size();i++)clist[i]->upd();
    if(clist.size()==1){//敌人全部死亡，成功
        QMessageBox::warning(this, tr("tql"), tr("tql"));
        Back();
        return true;
    }
    if(self->hp<=0){//玩家血量<=0，失败
        QMessageBox::warning( this, tr("wbhqt"), tr("wbhqt"));
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
    delete wphl;
    delete ui;
}
