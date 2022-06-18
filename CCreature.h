#pragma once
#ifndef CCREATURE_H
#include <QtWidgets>
#include <string>
#define CCREATURE_H
using std::string;
using std::vector;
const int XMX=20,YMX=14,TSizeX=50,TSizeY=50; //地图x方向大小，地图y方向大小，一格的x大小(单位像素），一格的y大小(单位像素）
extern int * plax,* play; //玩家当前在的位置(x,y)
const int dx[9]={0,1,0,-1,1,1,-1,-1,0},dy[9]={1,0,-1,0,1,-1,1,-1,0}; //9个方向对应的坐标变化
enum DIR{D,R,U,L,RD,RU,LD,LU,N};//9个方向，位置与dx,dy中对应
bool In(int x,int y); //(x,y)是否在游戏界面范围内
bool InRange(int x,int y,int r,int px = *plax,int py = *play); //(x,y)是否在游戏界面范围内距离(px,py)范围r的区域内（方形）
int getDir(int x,int y,int tx,int ty); //(x,y)到(tx,ty)的方向
class CCreature;
class Attack{ //攻击类
public:
    int id,atk,r; //种类，攻击力，范围
    string name; //名字
    Attack(int Id, int atk, int r, string name);
    bool InRange(int x,int y,int tx,int ty); //(x,y)是否在从(fx,fy)发射的攻击击中(tx,ty)的伤害范围内
    void hit(CCreature * & tar); //击中tar的效果
};
class CCreature{ //生物类（以后可能可以用来表示别的可互动物品）
public:
    int posx,posy,hp,id,mhp,mAtk; //x坐标，y坐标，血量，种类（0=自己,1=敌人），血量上限，近身攻击力
    QLabel * pic; //显示图片
    QProgressBar * hpbar; //血条
    vector<Attack> atk; //当前可用的攻击列表
    CCreature(int id,int px,int py,int HP,int mATK,QWidget *parent,string Path);
    void Move(int nx,int ny); //移动到(nx,ny)
    void rAtk(CCreature * & tar,Attack A); //该生物使用攻击A远程攻击生物tar
    void upd(); //更新状态（目前只有血条）
    bool Attack(CCreature * target); //近身攻击target
    int FindPath(int x = *plax,int y = *play); //用bfs找到当前到(x,y)的路线，返回当前该走的方向
    ~CCreature();
};

class Archer:public CCreature{
public:
    Archer(int id,int px,int py,int HP,int mATK,QWidget *parent,string Path):CCreature(id,px,py,HP,mATK,parent,Path)
    {

    }
}; //弓箭手，可远程攻击rAtk，血量更低，但攻击力更高
class Demoman:public CCreature{
public:
    Demoman(int id,int px,int py,int HP,int mATK,QWidget *parent,string Path):CCreature(id,px,py,HP,mATK,parent,Path)
    {

    }
}; //爆破兵，可使用bomb，使用前一轮会产生提示

#endif // CCREATURE_H
