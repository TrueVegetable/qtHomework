/********************************************************************************
** Form generated from reading UI file 'save_request.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_REQUEST_H
#define UI_SAVE_REQUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_save_request
{
public:
    QPushButton *Yesbutton;
    QPushButton *NoButton;
    QLabel *label;

    void setupUi(QWidget *save_request)
    {
        if (save_request->objectName().isEmpty())
            save_request->setObjectName(QString::fromUtf8("save_request"));
        save_request->resize(339, 159);
        Yesbutton = new QPushButton(save_request);
        Yesbutton->setObjectName(QString::fromUtf8("Yesbutton"));
        Yesbutton->setGeometry(QRect(60, 100, 80, 24));
        NoButton = new QPushButton(save_request);
        NoButton->setObjectName(QString::fromUtf8("NoButton"));
        NoButton->setGeometry(QRect(190, 100, 80, 24));
        label = new QLabel(save_request);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 231, 41));

        retranslateUi(save_request);

        QMetaObject::connectSlotsByName(save_request);
    } // setupUi

    void retranslateUi(QWidget *save_request)
    {
        save_request->setWindowTitle(QCoreApplication::translate("save_request", "Form", nullptr));
        Yesbutton->setText(QCoreApplication::translate("save_request", "YES", nullptr));
        NoButton->setText(QCoreApplication::translate("save_request", "NO", nullptr));
        label->setText(QCoreApplication::translate("save_request", "\346\217\220\347\244\272\357\274\232\350\257\245\345\255\230\346\241\243\344\271\213\345\211\215\345\267\262\350\242\253\345\255\230\345\202\250\357\274\201\346\230\257\345\220\246\350\246\206\347\233\226\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class save_request: public Ui_save_request {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_REQUEST_H
