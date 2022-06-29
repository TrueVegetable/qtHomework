#include "login.h"
#include "ui_login.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow1_2.h"
#include "registerpage.h"
#include "ui_registerpage.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <string>

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
        std::ifstream  inFile("users_registered.txt",std::ios::in);
        if(!inFile){
            QMessageBox::warning(this, tr("警告！"),
                        tr("该账号不存在！"),
                        QMessageBox::Yes);
            return ;
        }
        int num;
        inFile>>num;
        std::string array[100][2]; //假设不超过100个账号，数据库很小吧就当作！
        for(int i=0;i<num;i++){
            inFile>>array[i][0]>>array[i][1];
        }
        std::string usr = ui->usrLineEdit->text().toStdString();
        std::string pwd = ui->pwdLineEdit->text().toStdString();
        bool pass1 = false;//检查有没有这个账号
        bool pass2 = false;//检查密码是否正确
        std::string mark_usr;
        for(int i=0;i<num;i++){
            if(array[i][0]==usr){
                pass1 = true;
                if(array[i][1]==pwd){
                    mark_usr = array[i][0];
                    pass2 = true;
                }
                break;
            }
        }
        if(pass1&&pass2)
        {
            MainWindow1_2 * gw=new MainWindow1_2(mark_usr);
            gw->show();
            delete this;
        } else if(!pass1){
           QMessageBox::warning(this, tr("警告！"),
                       tr("该账号不存在！"),
                       QMessageBox::Yes);
        } else{
            QMessageBox::warning(this, tr("警告！"),
                        tr("账号或密码错误！"),
                        QMessageBox::Yes);
        }
        inFile.close();
}


void Login::on_regisButton_clicked()
{
    Registerpage * gwr=new Registerpage;
    gwr->show();
    delete this;
}


void Login::on_exitButton_clicked()
{
    MainWindow * gw=new MainWindow;
    gw->show();
    delete this;
}

