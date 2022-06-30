/********************************************************************************
** Form generated from reading UI file 'tmpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TMPWINDOW_H
#define UI_TMPWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TmpWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TmpWindow)
    {
        if (TmpWindow->objectName().isEmpty())
            TmpWindow->setObjectName(QStringLiteral("TmpWindow"));
        TmpWindow->resize(800, 600);
        TmpWindow->setStyleSheet(QStringLiteral("#TmpWindow{border-image: url(:/new/prefix1/image4.png);}"));
        centralwidget = new QWidget(TmpWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 180, 131, 61));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 180, 141, 61));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 280, 141, 61));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(370, 280, 141, 61));
        TmpWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TmpWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TmpWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TmpWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TmpWindow->setStatusBar(statusbar);

        retranslateUi(TmpWindow);

        QMetaObject::connectSlotsByName(TmpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TmpWindow)
    {
        TmpWindow->setWindowTitle(QApplication::translate("TmpWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TmpWindow", "Continue", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("TmpWindow", "Back to Menu", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("TmpWindow", "Save to Saving1", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("TmpWindow", "Save to Saving2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TmpWindow: public Ui_TmpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TMPWINDOW_H
