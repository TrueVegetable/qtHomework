#include "save_request.h"
#include "ui_save_request.h"
#include "tmpwindow.h"
#include "ui_tmpwindow.h"

save_request::save_request(int num,QWidget *parent,TmpWindow* n) :
    num1(num),QWidget(parent),now(n),
    ui(new Ui::save_request)
{
    ui->setupUi(this);
}

save_request::~save_request()
{
    delete ui;
}

void save_request::on_Yesbutton_clicked()
{
    now->re_save_quit(num1);
    delete this;
}


void save_request::on_NoButton_clicked()
{

    delete this;
}

