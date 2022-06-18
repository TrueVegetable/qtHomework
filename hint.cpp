#include "hint.h"
#include "ui_hint.h"

Hint::Hint(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hint)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,&QPushButton::released,this,&Hint::gotthis);
}

Hint::~Hint()
{
    delete ui;
}

void Hint::gotthis()
{
    delete this;
}
