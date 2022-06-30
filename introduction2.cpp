#include "introduction2.h"
#include "ui_introduction2.h"

Introduction2::Introduction2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Introduction2)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,&QPushButton::released,this,&Introduction2::close);
}

Introduction2::~Introduction2()
{
    delete ui;
}
