/********************************************************************************
** Form generated from reading UI file 'hint.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HINT_H
#define UI_HINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hint
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Hint)
    {
        if (Hint->objectName().isEmpty())
            Hint->setObjectName(QString::fromUtf8("Hint"));
        Hint->resize(800, 600);
        Hint->setStyleSheet(QString::fromUtf8("#Hints{border-image: url(:/new/prefix1/image4.png);}"));
        centralwidget = new QWidget(Hint);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 60, 461, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 190, 371, 20));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 120, 281, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 220, 511, 41));
        label_4->setFont(font1);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 280, 531, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        label_5->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(250, 330, 331, 20));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setUnderline(true);
        font3.setStrikeOut(false);
        label_6->setFont(font3);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 420, 321, 51));
        QFont font4;
        font4.setPointSize(13);
        pushButton->setFont(font4);
        pushButton->setStyleSheet(QString::fromUtf8("#QPushButton{border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));}\n"
"#Hint{border-image: url(:/new/prefix1/question.png);}"));
        Hint->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Hint);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Hint->setMenuBar(menubar);
        statusbar = new QStatusBar(Hint);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Hint->setStatusBar(statusbar);

        retranslateUi(Hint);

        QMetaObject::connectSlotsByName(Hint);
    } // setupUi

    void retranslateUi(QMainWindow *Hint)
    {
        Hint->setWindowTitle(QCoreApplication::translate("Hint", "Hints", nullptr));
        label->setText(QCoreApplication::translate("Hint", "Hint 1: On your right side is the weapon list.", nullptr));
        label_2->setText(QCoreApplication::translate("Hint", "Hint 2: Press \"f\" to choose weapon.", nullptr));
        label_3->setText(QCoreApplication::translate("Hint", "Try to make good use of it", nullptr));
        label_4->setText(QCoreApplication::translate("Hint", "Weapon list has told you corresponding numbers", nullptr));
        label_5->setText(QCoreApplication::translate("Hint", "Hint 3: Use your mouse to choose attacking range.", nullptr));
        label_6->setText(QCoreApplication::translate("Hint", "It will be shown with color \"red\"", nullptr));
        pushButton->setText(QCoreApplication::translate("Hint", "Thanks, I got it", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hint: public Ui_Hint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HINT_H
