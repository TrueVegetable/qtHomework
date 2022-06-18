/********************************************************************************
** Form generated from reading UI file 'mainwindow1_2.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW1_2_H
#define UI_MAINWINDOW1_2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow1_2
{
public:
    QWidget *centralwidget;
    QPushButton *NGbtm;
    QPushButton *RS1btm;
    QPushButton *RS2btm;
    QPushButton *CS1btm;
    QPushButton *CS2btm;
    QMenuBar *menubar;
    QMenu *menuWelcom;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow1_2)
    {
        if (MainWindow1_2->objectName().isEmpty())
            MainWindow1_2->setObjectName(QString::fromUtf8("MainWindow1_2"));
        MainWindow1_2->resize(400, 300);
        MainWindow1_2->setMaximumSize(QSize(2000, 2000));
        centralwidget = new QWidget(MainWindow1_2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        NGbtm = new QPushButton(centralwidget);
        NGbtm->setObjectName(QString::fromUtf8("NGbtm"));
        NGbtm->setGeometry(QRect(140, 40, 121, 41));
        RS1btm = new QPushButton(centralwidget);
        RS1btm->setObjectName(QString::fromUtf8("RS1btm"));
        RS1btm->setGeometry(QRect(70, 100, 121, 41));
        RS2btm = new QPushButton(centralwidget);
        RS2btm->setObjectName(QString::fromUtf8("RS2btm"));
        RS2btm->setGeometry(QRect(70, 170, 121, 41));
        CS1btm = new QPushButton(centralwidget);
        CS1btm->setObjectName(QString::fromUtf8("CS1btm"));
        CS1btm->setGeometry(QRect(220, 100, 121, 41));
        CS2btm = new QPushButton(centralwidget);
        CS2btm->setObjectName(QString::fromUtf8("CS2btm"));
        CS2btm->setGeometry(QRect(220, 170, 121, 41));
        MainWindow1_2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow1_2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 21));
        menuWelcom = new QMenu(menubar);
        menuWelcom->setObjectName(QString::fromUtf8("menuWelcom"));
        MainWindow1_2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow1_2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow1_2->setStatusBar(statusbar);

        menubar->addAction(menuWelcom->menuAction());

        retranslateUi(MainWindow1_2);

        QMetaObject::connectSlotsByName(MainWindow1_2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow1_2)
    {
        MainWindow1_2->setWindowTitle(QCoreApplication::translate("MainWindow1_2", "MainWindow", nullptr));
        NGbtm->setText(QCoreApplication::translate("MainWindow1_2", "New Game", nullptr));
        RS1btm->setText(QCoreApplication::translate("MainWindow1_2", "Read Saving1", nullptr));
        RS2btm->setText(QCoreApplication::translate("MainWindow1_2", "Read Saving2", nullptr));
        CS1btm->setText(QCoreApplication::translate("MainWindow1_2", "Clear Saving1", nullptr));
        CS2btm->setText(QCoreApplication::translate("MainWindow1_2", "Clear Saving2", nullptr));
        menuWelcom->setTitle(QCoreApplication::translate("MainWindow1_2", "Welcome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow1_2: public Ui_MainWindow1_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW1_2_H
