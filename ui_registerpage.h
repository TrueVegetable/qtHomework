/********************************************************************************
** Form generated from reading UI file 'registerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERPAGE_H
#define UI_REGISTERPAGE_H

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

class Ui_Registerpage
{
public:
    QLabel *label;
    QLineEdit *UsrLine;
    QLineEdit *PwdLine;
    QLineEdit *CheLine;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Registerpage)
    {
        if (Registerpage->objectName().isEmpty())
            Registerpage->setObjectName(QStringLiteral("Registerpage"));
        Registerpage->resize(400, 300);
        Registerpage->setStyleSheet(QStringLiteral("#Registerpage{border-image: url(:/new/prefix1/login_image.png);}"));
        label = new QLabel(Registerpage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 251, 41));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Handwriting"));
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        UsrLine = new QLineEdit(Registerpage);
        UsrLine->setObjectName(QStringLiteral("UsrLine"));
        UsrLine->setGeometry(QRect(160, 90, 181, 21));
        PwdLine = new QLineEdit(Registerpage);
        PwdLine->setObjectName(QStringLiteral("PwdLine"));
        PwdLine->setGeometry(QRect(160, 130, 181, 21));
        CheLine = new QLineEdit(Registerpage);
        CheLine->setObjectName(QStringLiteral("CheLine"));
        CheLine->setGeometry(QRect(160, 170, 181, 21));
        label_2 = new QLabel(Registerpage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 90, 81, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Handwriting"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255);"));
        label_3 = new QLabel(Registerpage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 130, 71, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Handwriting"));
        font2.setPointSize(10);
        font2.setBold(true);
        label_3->setFont(font2);
        label_3->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        label_4 = new QLabel(Registerpage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 170, 151, 16));
        QFont font3;
        font3.setFamily(QStringLiteral("Lucida Handwriting"));
        font3.setPointSize(9);
        font3.setBold(true);
        label_4->setFont(font3);
        label_4->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        pushButton = new QPushButton(Registerpage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 230, 80, 24));
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(Registerpage);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 230, 80, 24));
        pushButton_2->setFont(font1);

        retranslateUi(Registerpage);

        QMetaObject::connectSlotsByName(Registerpage);
    } // setupUi

    void retranslateUi(QDialog *Registerpage)
    {
        Registerpage->setWindowTitle(QApplication::translate("Registerpage", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Registerpage", "Become a New Player!", Q_NULLPTR));
        label_2->setText(QApplication::translate("Registerpage", "Username:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Registerpage", "Password:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Registerpage", "Check your Password:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Registerpage", "Register", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Registerpage", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Registerpage: public Ui_Registerpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERPAGE_H
