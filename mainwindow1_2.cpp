#include "mainwindow1_2.h"
#include "ui_mainwindow1_2.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "CCreature.h"
#include <iostream>
#include <fstream>

MainWindow1_2::MainWindow1_2(std::string name,QWidget *parent) :
    filename(name),QMainWindow(parent),
    ui(new Ui::MainWindow1_2)
{
    ui->setupUi(this);
}

MainWindow1_2::~MainWindow1_2()
{
    delete ui;
}

void MainWindow1_2::on_NGbtm_clicked() //开始新游戏
{
    MainWindow2 * gw=new MainWindow2(filename);
    gw->show();
    delete this;
}


void MainWindow1_2::on_RS1btm_clicked()
{
    std::ifstream inFile((filename+"_saving1.txt").c_str());
    if(!inFile){
        QMessageBox::warning(this, tr("错误！"),
                    tr("无相应存档！"),
                    QMessageBox::Yes);
    } else {
        inFile.close();
        read_archive((filename).c_str(),1);
        delete this;
    }

}


void MainWindow1_2::on_CS1btm_clicked()
{
    if(std::remove((filename+"_saving1.txt").c_str())==0){
        QMessageBox::warning(this, tr("删除成功！"),
                    tr("删除存档成功！"),
                    QMessageBox::Yes);
     } else {
        QMessageBox::warning(this, tr("删除失败！"),
                    tr("无相应存档或存档已打开！"),
                    QMessageBox::Yes);
    }

}


void MainWindow1_2::on_RS2btm_clicked()
{
    std::ifstream inFile((filename+"_saving2.txt").c_str());
    if(!inFile){
        QMessageBox::warning(this, tr("错误！"),
                    tr("无相应存档！"),
                    QMessageBox::Yes);
    } else {
        inFile.close();
        read_archive((filename).c_str(),2);
        delete this;
    }
}




void MainWindow1_2::on_CS2btm_clicked()
{
    if(std::remove((filename+"_saving2.txt").c_str())==0){
        QMessageBox::warning(this, tr("删除成功！"),
                    tr("删除存档成功！"),
                    QMessageBox::Yes);
     } else {
        QMessageBox::warning(this, tr("删除失败！"),
                    tr("无相应存档或存档已打开！"),
                    QMessageBox::Yes);
    }
}

void MainWindow1_2::read_archive(std::string usrname,int num){

    std::string filename=usrname;
    if(num==1) filename+="_saving1.txt";
    else if(num==2) filename+="_saving2.txt";
    std::ifstream  inFile((filename).c_str(),std::ios::in);
    int level; inFile>>level;
    MainWindow2 * gw2=new MainWindow2(usrname,level,1);
    //绘制地图
    memset(gw2->mapp,0,XMX*YMX*sizeof(int));
    for(int i=0;i<XMX;i++){
        for(int j=0;j<YMX;j++){
            inFile>>gw2->mapp[i][j];
        }
    }
    gw2->showmapp();
    //地图绘制完毕
    std::cout<<"here1"<<std::endl;
    int id,px,py,mhp,hp,matk,cd1,cd2,cd3;
    inFile>>id>>px>>py>>mhp>>hp>>matk;
    inFile>>cd1>>cd2>>cd3;
    CCreature * u=new CCreature(id,px,py,mhp,matk,gw2->use_ui()->centralwidget,":/new/prefix1/me.png");
    gw2->self = u;
    gw2->self->hp = hp;
    gw2->self->atk.push_back(Attack(0,3+(level+1)/3,std::min(5,3+(level+2)/5),"Shoot",1));
    gw2->self->atk.push_back(Attack(1,2+(level+2)/3,std::min(6,4+level/5),"Bomb",3));
    gw2->self->atk.push_back(Attack(2,3+level/3,std::min(7,5+level/4),"Arrow",2)); //赋予武器
    gw2->self->atk[0].curcd=cd1;
    gw2->self->atk[1].curcd=cd2;
    gw2->self->atk[2].curcd=cd3;
    gw2->self->upd();
    std::cout<<"here2"<<std::endl;
    plax = &(gw2->self->posx); play= &(gw2->self->posy);
    //gw2->clist.clear();

//    for(int i=0;i<TSizeX;i++){
//        for(int j=0;j<TSizeY;j++)
//            if(gw2->cmp[i][j]) gw2->cmp[i][j] = nullptr;
//    }
    std::cout<<"here3"<<std::endl;
    gw2->clist.push_back(u);
    std::cout<<"here3.1"<<std::endl;
    gw2->cmp[px][py] = u;
    //if(px!=0||py!=0) delete gw2->cmp[0][0];
    std::cout<<"here3.5"<<std::endl;
    int len_clist;
    inFile>>len_clist;
    for(int i =1;i<len_clist;i++){
        inFile>>id>>px>>py>>mhp>>hp>>matk;
        std::cout<<"here41"<<std::endl;
        std::cout<<id<<" "<<px<<" "<<py<<" "<<mhp<<" "<<matk<<std::endl;
        CCreature* c1 = new CCreature(id,px,py,mhp,matk,gw2->use_ui()->centralwidget,":/new/prefix1/Enemy.png");
        std::cout<<"here42"<<std::endl;
        c1->hp = hp;
        std::cout<<"here43"<<std::endl;
        c1->upd();
        std::cout<<"here44"<<std::endl;
        gw2->cmp[px][py] = c1;
        std::cout<<"here46"<<std::endl;
        gw2->clist.push_back(c1);
    }
    std::cout<<"here45"<<std::endl;
    inFile>>gw2->mode;
    inFile>>gw2->mx;
    inFile>>gw2->my;
    inFile.close();
    gw2->UpdWpList();
    gw2->show();
}

/* 存储格式：.txt
 * row0: lvl
 * row1: self ( in sequence: int Id,int px,int py,int mhp,int hp,int mATK )
 * row2: curcd of each weapon ( now only "me" have that )
 * row3: size of clist - n
 * row4-(n+2): a creature in clist per row EXCEPT SELF ( in sequence: int Id,int px,int py,int mhp,int hp,int mATK )
 * row(n+3): mode, mx, my in sequence
 * !!!different numbers in one row will be separated by a whitespace
 */


