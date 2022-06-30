/********************************************************************************
** Form generated from reading UI file 'introduction2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTRODUCTION2_H
#define UI_INTRODUCTION2_H

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

class Ui_Introduction2
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Introduction2)
    {
        if (Introduction2->objectName().isEmpty())
            Introduction2->setObjectName(QStringLiteral("Introduction2"));
        Introduction2->resize(800, 500);
        Introduction2->setStyleSheet(QStringLiteral("#Introduction2{border-image: url(:/new/prefix1/hint_image.png);}"));
        centralwidget = new QWidget(Introduction2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 50, 300, 51));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Handwriting"));
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 120, 671, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Handwriting"));
        font1.setPointSize(13);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 190, 611, 51));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 240, 700, 81));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 320, 600, 71));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Handwriting"));
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setUnderline(true);
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 400, 180, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Lucida Handwriting"));
        font3.setPointSize(12);
        font3.setBold(true);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/button_yellow.png);\n"
"color:rgb(255, 255, 255);"));
        Introduction2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Introduction2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Introduction2->setMenuBar(menubar);
        statusbar = new QStatusBar(Introduction2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Introduction2->setStatusBar(statusbar);

        retranslateUi(Introduction2);

        QMetaObject::connectSlotsByName(Introduction2);
    } // setupUi

    void retranslateUi(QMainWindow *Introduction2)
    {
        Introduction2->setWindowTitle(QApplication::translate("Introduction2", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("Introduction2", "ATTENTION!", Q_NULLPTR));
        label_2->setText(QApplication::translate("Introduction2", "From now on, you  will meet a new kind of enemy called Kuroro.", Q_NULLPTR));
        label_3->setText(QApplication::translate("Introduction2", "They can be more delicate but with higher aggresivity.", Q_NULLPTR));
        label_4->setText(QApplication::translate("Introduction2", "Demoman has 3 bombs and will attack you whenever it has chances.", Q_NULLPTR));
        label_5->setText(QApplication::translate("Introduction2", "So pay attetion, do not stand too close to them!", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Introduction2", "Good Luck", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Introduction2: public Ui_Introduction2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRODUCTION2_H
