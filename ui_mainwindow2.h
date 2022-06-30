/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QAction *actionPause;
    QAction *actionQuit;
    QAction *actionHints;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName(QString::fromUtf8("MainWindow2"));
        MainWindow2->resize(1366, 768);
        MainWindow2->setMinimumSize(QSize(1366, 768));
        MainWindow2->setMaximumSize(QSize(1366, 768));
        MainWindow2->setStyleSheet(QString::fromUtf8("#MainWindow2{border-image: url(:/new/prefix1/mainwindow2.png);}"));
        MainWindow2->setMouseTracking(true);
        actionPause = new QAction(MainWindow2);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionQuit = new QAction(MainWindow2);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionHints = new QAction(MainWindow2);
        actionHints->setObjectName(QString::fromUtf8("actionHints"));
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(true);//不加无法追踪鼠标
        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1366, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow2->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionHints);
        menuFile->addAction(actionPause);
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow2);

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "MainWindow", nullptr));
        actionPause->setText(QCoreApplication::translate("MainWindow2", "Pause", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow2", "Quit", nullptr));
        actionHints->setText(QCoreApplication::translate("MainWindow2", "Hints", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow2", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
