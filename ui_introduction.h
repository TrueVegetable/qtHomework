/********************************************************************************
** Form generated from reading UI file 'introduction.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTRODUCTION_H
#define UI_INTRODUCTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Introduction
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Introduction)
    {
        if (Introduction->objectName().isEmpty())
            Introduction->setObjectName(QStringLiteral("Introduction"));
        Introduction->resize(800, 500);
        Introduction->setStyleSheet(QStringLiteral("#Introduction{border-image: url(:/new/prefix1/hint_image.png);}"));
        centralwidget = new QWidget(Introduction);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 370, 180, 41));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Handwriting"));
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/button_yellow.png);\n"
"color:rgb(255, 255, 255);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 60, 200, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Handwriting"));
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 140, 621, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Handwriting"));
        font2.setPointSize(13);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 200, 600, 41));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 270, 1, 41));
        QFont font3;
        font3.setPointSize(13);
        label_4->setFont(font3);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 270, 700, 51));
        QFont font4;
        font4.setFamily(QStringLiteral("Lucida Handwriting"));
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setUnderline(true);
        label_5->setFont(font4);
        label_5->setAlignment(Qt::AlignCenter);
        Introduction->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Introduction);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Introduction->setMenuBar(menubar);
        statusbar = new QStatusBar(Introduction);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Introduction->setStatusBar(statusbar);

        retranslateUi(Introduction);

        QMetaObject::connectSlotsByName(Introduction);
    } // setupUi

    void retranslateUi(QMainWindow *Introduction)
    {
        Introduction->setWindowTitle(QApplication::translate("Introduction", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Introduction", "Good Luck", Q_NULLPTR));
        label->setText(QApplication::translate("Introduction", "ATTENTION!", Q_NULLPTR));
        label_2->setText(QApplication::translate("Introduction", "From now on, you  will meet a new kind of enemy called Hisoka.", Q_NULLPTR));
        label_3->setText(QApplication::translate("Introduction", "They can be more delicate but with higher aggresivity.", Q_NULLPTR));
        label_4->setText(QApplication::translate("Introduction", "Archer has 3 arrows and will attack you remotely whenever it has chances.", Q_NULLPTR));
        label_5->setText(QApplication::translate("Introduction", "So pay attention, do not stand on its diagonal line.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Introduction: public Ui_Introduction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRODUCTION_H
