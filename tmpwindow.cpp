#include "tmpwindow.h"
#include "ui_tmpwindow.h"
#include "mainwindow.h"
#include "mainwindow1_2.h"
#include "ui_mainwindow1_2.h"
#include "save_request.h"
#include "ui_save_request.h"
#include <iostream>
TmpWindow::TmpWindow(QWidget *parent,MainWindow2 *n) :
    QMainWindow(parent),
    now(n),
    ui(new Ui::TmpWindow)
{
    ui->setupUi(this);

    setWindowTitle("Options");

    connect(this->ui->pushButton,&QPushButton::released,this,&TmpWindow::close);
    connect(this->ui->pushButton_2,&QPushButton::released,this,&TmpWindow::t_quit);
    connect(this->ui->pushButton_3,&QPushButton::released,this,&TmpWindow::t_save_quit1);
    connect(this->ui->pushButton_4,&QPushButton::released,this,&TmpWindow::t_save_quit2);

} //中转界面三个按钮的操作

TmpWindow::~TmpWindow()
{
    delete ui;
}

void TmpWindow::t_quit()
{
    MainWindow1_2 *N_window = new MainWindow1_2(now->usrname);
    N_window->show();
    delete now; //删掉上一层的游戏界面，返回主菜单
    delete this; //删掉自己
}

void TmpWindow::t_save_quit1()
{
    if(now->save_archive(1)){
        QMessageBox::warning(this, tr("存档成功！"),
                    tr("已将游戏进度成功存至saving1！"),
                    QMessageBox::Yes);
        t_quit();
    } else {
        save_request* sr1 = new save_request(1,nullptr,this);
        sr1->show();
    }
}

void TmpWindow::t_save_quit2()
{
    if(now->save_archive(2)){
        QMessageBox::warning(this, tr("存档成功！"),
                    tr("已将游戏进度成功存至saving2！"),
                    QMessageBox::Yes);
        t_quit();
    } else {
        save_request* sr1 = new save_request(2,nullptr,this);
        sr1->show();

    }
}

void TmpWindow::re_save_quit(int num){
    std::string s1="";
    if(num==1) s1 = (now->usrname+"_saving1.txt");
    else if(num==2) s1 = (now->usrname+"_saving2.txt");
    else{
        return;
    }
    std::cout<<"0000000"<<std::endl;
    if(std::remove(s1.c_str())==0 && now->save_archive(num)){
        QMessageBox::warning(this, tr("覆盖成功！"),
                    tr("存档 2 已覆盖为新存档！"),
                    QMessageBox::Yes);
    }else{ //原则上不会发生，但双保险
        QMessageBox::warning(this, tr("覆盖失败！"),
                    tr("存档失败！"),
                    QMessageBox::Yes);
    }
}






