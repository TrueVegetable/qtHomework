#include "introduction.h"
#include "ui_introduction.h"

Introduction::Introduction(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Introduction)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,&QPushButton::released,this,&Introduction::close);
}

Introduction::~Introduction()
{
    delete ui;
}
