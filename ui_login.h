/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *usrLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *pwdLineEdit;
    QLabel *label_3;
    QPushButton *loginButton;
    QPushButton *exitButton;
    QPushButton *regisButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 300);
        usrLineEdit = new QLineEdit(Login);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));
        usrLineEdit->setGeometry(QRect(140, 100, 191, 21));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 100, 61, 16));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 160, 61, 16));
        pwdLineEdit = new QLineEdit(Login);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(140, 160, 191, 21));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 40, 101, 31));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(200, 240, 80, 24));
        exitButton = new QPushButton(Login);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(290, 240, 80, 24));
        regisButton = new QPushButton(Login);
        regisButton->setObjectName(QStringLiteral("regisButton"));
        regisButton->setGeometry(QRect(40, 240, 101, 24));

        retranslateUi(Login);
        QObject::connect(exitButton, SIGNAL(clicked()), Login, SLOT(close()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "Username", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "Password", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "Welcome!", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Login", "Login", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Login", "Cancel", Q_NULLPTR));
        regisButton->setText(QApplication::translate("Login", "Register", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
