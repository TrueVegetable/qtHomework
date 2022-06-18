#include "login.h"
#include "ui_login.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow1_2.h"

#include<QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    // 判断用户名和密码是否正确，
        // 如果错误则弹出警告对话框
        if(ui->usrLineEdit->text() == tr("cxj") &&
               ui->pwdLineEdit->text() == tr("handsome"))
        {
            MainWindow1_2 * gw=new MainWindow1_2;
            gw->show();
            delete this;
        } else {
           QMessageBox::warning(this, tr("警告！"),
                       tr("用户名或密码错误！"),
                       QMessageBox::Yes);
        }
}

