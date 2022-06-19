#include "CCreature.h"
#include <QtWidgets>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <random>
using std::abs;
typedef std::pair<int,int> pii;
int * plax=nullptr, * play=nullptr; //玩家、敌人
bool In(int x,int y){
    return x >= 0 && x < XMX && y >= 0 && y < YMX;
} //判断是否在地图范围内
bool InRange(int x,int y,int r,int px,int py){
    return In(x,y) && std::max(abs(px-x),abs(py-y)) <= r;
} //(x,y)是否在游戏界面范围内距离(px,py)范围r的区域内（方形）
int getDir(int x,int y,int tx,int ty){
    if(x < tx){ //R
        if(y < ty)return RD;
        if(y > ty)return RU;
        return R;
    }
    else
    if(x > tx){ //L
        if(y < ty)return LD;
        if(y > ty)return LU;
        return L;
    }
    else{ //x相等
        if(y < ty)return D;
        if(y > ty)return U;
        return N;
    }

} //direction

Attack::Attack(int Id,int Atk,int R,string Name,int CD):id(Id),atk(Atk),r(R),cd(CD),curcd(0),name(Name){

}
bool Attack::InRange(int x,int y,int tx,int ty){
    switch(id){
        case 0:return x == tx && y == ty; //单体攻击
        case 1:return ::InRange(x,y,1,tx,ty); //范围攻击
        case 2: //直线攻击
            int cx=*plax,cy=*play;
            int di=std::min(abs(tx-cx),abs(cy-ty)),ort=std::max(abs(tx-cx),abs(cy-ty))-di;//di(agonal):走对角次数 ort(hogonal):走上下左右次数
            int cnt=0;//原理：设需要走di次斜线和ort次上下左右，cnt>0时走上下左右，cnt<=0时走斜线，每次走斜线+ort,走上下左右-di,保证近似于直线
            do{
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
                if(x==cx&&y==cy)return true;
            }while(getDir(cx,cy,tx,ty)!=N);
            return false;
    }
} //(x,y)是否在从(fx,fy)发射的攻击击中(tx,ty)的伤害范围内
void Attack::hit(CCreature * & tar){
    tar->hp-=atk;
}

void CCreature::rAtk(CCreature * & tar,class Attack & A){
    A.hit(tar);
}
CCreature::CCreature(int Id,int px,int py,int HP,int mATK,QWidget *parent,std::string Path){
    id=Id,posx=px,posy=py,mAtk=mATK,hp=mhp=HP;
    pic=new QLabel(parent);
    pic->setMouseTracking(true); //此处不加会导致鼠标在其上时不按鼠标按键时不追踪鼠标移动
    //pic->setObjectName(QString::fromUtf8("label"));
    pic->setGeometry(QRect(px*TSizeX, py*TSizeY, TSizeX, TSizeY));
    pic->setPixmap(QPixmap(QString::fromStdString(Path)));
    pic->setScaledContents(true);
    pic->show(); //设置人物形象
    hpbar=new QProgressBar(parent);
    hpbar->setMouseTracking(true);
    hpbar->setMaximum(mhp);
    hpbar->setMinimum(0);
    hpbar->setValue(hp);
    hpbar->setGeometry(px*TSizeX,py*TSizeY,TSizeX,TSizeY/5);
    hpbar->show(); //设置血条
}
void CCreature::Move(int nx,int ny){
    posx=nx,posy=ny;
    pic->move(nx*TSizeX,ny*TSizeY);
    hpbar->move(nx*TSizeX,ny*TSizeY);
} //人物移动
bool CCreature::Attack(CCreature * target){
    target->hp-=mAtk;
    return target->hp<=0;
}
CCreature::~CCreature(){
    delete pic;
    delete hpbar;
}
void CCreature::upd(){
    hpbar->setValue(hp);
} //更新血条
struct cord{
    int x,y,v,fm;
    friend bool operator >(const cord &a,const cord &b){
        return a.v>b.v;
    }
    cord(int a,int b,int c,int d):x(a),y(b),v(c),fm(d){}
}; //表示坐标
int CCreature::FindPath(CCreature * mp[XMX][YMX],int x,int y){
      int vis[XMX][YMX];
      memset(vis,0,sizeof(vis));
      std::queue<cord> q;
      vis[posx][posy]=1;
      for(int i=0;i<8;i++){
          int nx=posx+dx[i],ny=posy+dy[i];
          if(nx==x&&ny==y)return i;
          if(In(nx,ny)&&!mp[nx][ny])q.push(cord(nx,ny,1,i)),vis[nx][ny]=1;
      }
      while(!q.empty()){
          cord cur=q.front();q.pop();
          for(int i=0;i<8;i++){
              int nx=cur.x+dx[i],ny=cur.y+dy[i];
              if(nx==x&&ny==y)return cur.fm;
              if(!In(nx,ny)||vis[nx][ny]||mp[nx][ny])continue;
              q.push(cord(nx,ny,cur.v+1,cur.fm)),vis[nx][ny]=1;
          }
      }
      return N;
} //用bfs找到当前到(x,y)的路线，返回当前该走的方向
