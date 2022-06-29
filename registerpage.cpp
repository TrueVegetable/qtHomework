#include "registerpage.h"
#include "ui_registerpage.h"
#include <fstream>
#include<QMessageBox>
#include<iostream>
#include "login.h"

Registerpage::Registerpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registerpage)
{
    ui->setupUi(this);
}

Registerpage::~Registerpage()
{
    delete ui;
}

void Registerpage::on_pushButton_clicked()
{
    std::string usr = ui->UsrLine->text().toStdString();
    std::string pwd = ui->PwdLine->text().toStdString();
    std::string check = ui->CheLine->text().toStdString();
    if(pwd!=check){
        QMessageBox::warning(this, tr("密码错误"),
                    tr("两次输入的密码不一致！"),
                    QMessageBox::Yes);
    }else{
        std::ifstream inFile("users_registered.txt",std::ios::in);
        if(!inFile){
            std::ofstream outFile("users_registered.txt",std::ios::in);
            outFile<<0;
            outFile.close();
            std::ifstream inFile("users_registered.txt",std::ios::in);
        }
        int num=0; inFile>>num;
        if(num>=100){
            QMessageBox::warning(this, tr("数据库错误"),
                        tr("数据库已满，无法添加新用户！"),
                        QMessageBox::Yes);
        } else{
            std::string array[100][2];
            bool registerbefore=false;//检查之前是否有注册过
            for(int i=0;i<num;i++){
                inFile>>array[i][0]; inFile>>array[i][1];
                if(usr==array[i][0]){
                    inFile.close();
                    registerbefore=true;
                    break;
                }
            }
            if(registerbefore){
                QMessageBox::warning(this, tr("注册错误"),
                            tr("该用户名已被使用！"),
                            QMessageBox::Yes);
            }else{
                array[num][0] = usr; array[num][1] = pwd;
                num++;
                inFile.close();
                std::ofstream outFile("users_registered.txt", std::ofstream::out | std::ofstream::trunc);
                outFile<<num<<std::endl;
                for(int i=0;i<num;i++){
                    outFile<<array[i][0]<<" "<<array[i][1]<<std::endl;
                }
                outFile.close();
                QMessageBox::warning(this, tr("Success"),
                            tr("注册成功！"),
                            QMessageBox::Yes);
                Login * gw=new Login;
                gw->show();
                delete this;
            }

        }
    }


}


void Registerpage::on_pushButton_2_clicked()
{
    exit(0);
}

