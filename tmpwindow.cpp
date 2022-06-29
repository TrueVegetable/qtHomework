#include "tmpwindow.h"
#include "ui_tmpwindow.h"
#include "mainwindow.h"
#include "mainwindow1_2.h"
#include "ui_mainwindow1_2.h"

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
        QMessageBox::warning(this, tr("存档失败！"),
                    tr("该存档已存在，无法重复存档！"),
                    QMessageBox::Yes);
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
        QMessageBox::warning(this, tr("存档失败！"),
                    tr("该存档已存在，无法重复存档！"),
                    QMessageBox::Yes);
    }
}


