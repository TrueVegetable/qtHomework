#pragma once
#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H
#include "CCreature.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QtWidgets>
#include <vector>

using std::vector;
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT
public:
    vector<CCreature *> clist; //生物列表
    CCreature * self; //玩家
    vector<QLabel *> showr; //范围标记
    vector<QLabel *> showwp; //武器显示界面
    vector<QLabel *> showaoe;//伤害范围标记
    QLabel * wphl; //当前选择武器高亮(WeaPon HighLight)
    CCreature * cmp[TSizeX][TSizeY]; //按位置存储生物
    int mode,mx,my; //mode表示当前进行的行动：0:移动，-1:选择武器，1~n:为发射武器mode选择目标   mx,my:目标指示器当前所在位置
    MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();
    void Back(); //退出游戏
    template<typename T>
    void trace(int fx,int fy,int tx,int ty,T act);//对(fx,fy)到(tx,ty)上的每个位置调用T函数
    void createShowaoe(int tx,int ty,Attack atk);
    bool checkDie(int nx,int ny); //检查在(nx,ny)生物是否死亡，如死亡则处理
    bool checkDie(CCreature * & tar);//检查生物tar是否死亡，如死亡则处理
    void rAtk(CCreature * & src,int tx,int ty,Attack A); //src使用攻击A远程攻击位置(tx,ty)
    void Upd_E(); //敌人行动
    void Move(int dir); //自己进行行动
    bool Upd_All(); //行动完后调用，进行所有不由玩家操控的行动与更新（包括敌人行动，检查游戏状态等）
    void UpdWpList(int ch=0); //更新武器显示界面
    void keyPressEvent(QKeyEvent *k); //qt自带函数，按下键盘按键时调用
    void mouseMoveEvent(QMouseEvent *k); //qt自带函数，鼠标移动时调用
    void mousePressEvent(QMouseEvent *k);//qt自带函数，按下鼠标按键时调用
    void paintEvent(QPaintEvent *); //画图事件
    int pposx,pposy,pposx2,pposy2; //远程攻击的起点和终点
    void option(); //弹出tmpwindow
    void hint(); //弹出提示框
    bool save_archive(int num); //存档
    Ui::MainWindow2 * use_ui(){ //只在读取游戏存档的时候生成CCreature时用
        return ui;
    }
private:
    Ui::MainWindow2 *ui;
};
#endif // MAINWINDOW2_H
