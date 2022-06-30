/********************************************************************************
** Form generated from reading UI file 'mainwindow1_2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW1_H
#define UI_MAINWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
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
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow1_2)
    {
        if (MainWindow1_2->objectName().isEmpty())
            MainWindow1_2->setObjectName(QStringLiteral("MainWindow1_2"));
        MainWindow1_2->resize(400, 300);
        MainWindow1_2->setMaximumSize(QSize(2000, 2000));
        MainWindow1_2->setStyleSheet(QStringLiteral("#MainWindow1_2{border-image: url(:/new/prefix1/window1_2.png);}"));
        centralwidget = new QWidget(MainWindow1_2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        NGbtm = new QPushButton(centralwidget);
        NGbtm->setObjectName(QStringLiteral("NGbtm"));
        NGbtm->setGeometry(QRect(140, 40, 121, 41));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Handwriting"));
        font.setPointSize(10);
        NGbtm->setFont(font);
        NGbtm->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/button_blue.png);\n"
"color:rgb(255, 255, 255);"));
        RS1btm = new QPushButton(centralwidget);
        RS1btm->setObjectName(QStringLiteral("RS1btm"));
        RS1btm->setGeometry(QRect(70, 100, 121, 41));
        RS1btm->setFont(font);
        RS1btm->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/button_yellow.png);\n"
"color:rgb(255, 255, 255);"));
        RS2btm = new QPushButton(centralwidget);
        RS2btm->setObjectName(QStringLiteral("RS2btm"));
        RS2btm->setGeometry(QRect(70, 170, 121, 41));
        RS2btm->setFont(font);
        RS2btm->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/button_yellow.png);\n"
"color:rgb(255, 255, 255);"));
        CS1btm = new QPushButton(centralwidget);
        CS1btm->setObjectName(QStringLiteral("CS1btm"));
        CS1btm->setGeometry(QRect(220, 100, 121, 41));
        CS1btm->setFont(font);
        CS1btm->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/button_grey.png);\n"
"color:rgb(255, 255, 255);"));
        CS2btm = new QPushButton(centralwidget);
        CS2btm->setObjectName(QStringLiteral("CS2btm"));
        CS2btm->setGeometry(QRect(220, 170, 121, 41));
        CS2btm->setFont(font);
        CS2btm->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/button_grey.png);\n"
"color:rgb(255, 255, 255);"));
        MainWindow1_2->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow1_2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow1_2->setStatusBar(statusbar);

        retranslateUi(MainWindow1_2);

        QMetaObject::connectSlotsByName(MainWindow1_2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow1_2)
    {
        MainWindow1_2->setWindowTitle(QApplication::translate("MainWindow1_2", "MainWindow", Q_NULLPTR));
        NGbtm->setText(QApplication::translate("MainWindow1_2", "New Game", Q_NULLPTR));
        RS1btm->setText(QApplication::translate("MainWindow1_2", "Read Saving1", Q_NULLPTR));
        RS2btm->setText(QApplication::translate("MainWindow1_2", "Read Saving2", Q_NULLPTR));
        CS1btm->setText(QApplication::translate("MainWindow1_2", "Clear Saving1", Q_NULLPTR));
        CS2btm->setText(QApplication::translate("MainWindow1_2", "Clear Saving2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow1_2: public Ui_MainWindow1_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW1_H
