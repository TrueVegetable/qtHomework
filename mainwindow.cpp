#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow_help.h"
#include "ui_mainwindow_help.h"
#include "login.h"
#include "ui_login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,&QPushButton::released,this,&MainWindow::NewWindow);
    connect(this->ui->pushButton_2,&QPushButton::released,this,&MainWindow::Quit); //两个button，start和quit
    connect(this->ui->pushButton_3,&QPushButton::released,this,&MainWindow::ShowHelp);

    //ui->pushButton->setIcon(QIcon(":/new/prefix1/button_blue.png"));
    //ui->pushButton->setIconSize(QSize(300, 60));
    //ui->pushButton_2->setIcon(QIcon(":/new/prefix1/people.png"));
    //ui->pushButton_3->setIcon(QIcon(":/new/prefix1/people.png"));//button的图标

    setWindowTitle("Main Menu");
}
void MainWindow::NewWindow(){
    Login * gw=new Login;
    gw->show();
    delete this;
} //点击start之后，弹出mainwindow2，删掉自己
void MainWindow::Quit(){
    exit(0);
}
void MainWindow::ShowHelp(){
    MainWindow_help * gw2=new MainWindow_help;
    gw2->show();
    //delete this;
} //点击start之后，弹出mainwindow2，删掉自己
MainWindow::~MainWindow()
{
    delete ui;
}

