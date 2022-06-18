#include "mainwindow1_2.h"
#include "ui_mainwindow1_2.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <iostream>
#include <fstream>

MainWindow1_2::MainWindow1_2(QWidget *parent) :
    QMainWindow(parent),
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
    MainWindow2 * gw=new MainWindow2;
    gw->show();
    delete this;
}


void MainWindow1_2::on_RS1btm_clicked()
{
    std::ifstream inFile("saving1.txt");
    if(!inFile){
        QMessageBox::warning(this, tr("错误！"),
                    tr("无相应存档！"),
                    QMessageBox::Yes);
    } else {
        inFile.close();
        read_archive("saving1.txt");
        delete this;
    }

}


void MainWindow1_2::on_CS1btm_clicked()
{
    if(std::remove("saving1.txt")==0){
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
    std::ifstream inFile("saving2.txt");
    if(!inFile){
        QMessageBox::warning(this, tr("错误！"),
                    tr("无相应存档！"),
                    QMessageBox::Yes);
    } else {
        inFile.close();
        read_archive("saving2.txt");
        delete this;
    }
}




void MainWindow1_2::on_CS2btm_clicked()
{
    if(std::remove("saving2.txt")==0){
        QMessageBox::warning(this, tr("删除成功！"),
                    tr("删除存档成功！"),
                    QMessageBox::Yes);
     } else {
        QMessageBox::warning(this, tr("删除失败！"),
                    tr("无相应存档或存档已打开！"),
                    QMessageBox::Yes);
    }
}

void MainWindow1_2::read_archive(char const* filename){

    std::ifstream  inFile(filename,std::ios::in);
    MainWindow2 * gw2=new MainWindow2;
    int id,px,py,mhp,hp,matk;
    inFile>>id>>px>>py>>mhp>>hp>>matk;
    gw2->self = new CCreature(id,px,py,mhp,matk,gw2->use_ui()->centralwidget,":/new/prefix1/me.png");
    gw2->self->hp = hp;
    gw2->self->upd();
    plax = &(gw2->self->posx); play= &(gw2->self->posy);
    gw2->clist.clear();
    for(int i=0;i<TSizeX;i++){
        for(int j=0;j<TSizeY;j++)
            delete gw2->cmp[i][j];
    }
    gw2->clist.push_back(gw2->self);
    gw2->cmp[px][py] = gw2->self;
    int len_clist;
    inFile>>len_clist;
    for(int i =1;i<len_clist;i++){
        inFile>>id>>px>>py>>mhp>>hp>>matk;
        CCreature* c1 = new CCreature(id,px,py,mhp,matk,gw2->use_ui()->centralwidget,":/new/prefix1/Enemy.png");
        c1->hp = hp;
        c1->upd();
        gw2->cmp[px][py] = c1;
        gw2->clist.push_back(c1);
    }
    inFile>>gw2->mode;
    inFile>>gw2->mx;
    inFile>>gw2->my;
    inFile.close();
    gw2->show();
}

/* 存储格式：.txt
 * row1: self ( in sequence: int Id,int px,int py,int mhp,int hp,int mATK )
 * row2: size of clist - n
 * row3-(n+1): a creature in clist per row EXCEPT SELF ( in sequence: int Id,int px,int py,int mhp,int hp,int mATK )
 * row(n+2): mode, mx, my in sequence
 * !!!different numbers in one row will be separated by a whitespace
 */

