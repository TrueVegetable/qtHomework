#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,&QPushButton::released,this,&MainWindow::NewWindow);
    connect(this->ui->pushButton_2,&QPushButton::released,this,&MainWindow::Quit);
}
void MainWindow::NewWindow(){
    MainWindow2 * gw=new MainWindow2;
    gw->show();
    delete this;
}
void MainWindow::Quit(){
    exit(0);
}
MainWindow::~MainWindow()
{
    delete ui;
}

