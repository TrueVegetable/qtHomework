#ifndef INTRODUCTION2_H
#define INTRODUCTION2_H

#include <QMainWindow>
#include "mainwindow2.h"
#include "ui_mainwindow2.h"

namespace Ui {
class Introduction2;
}

class Introduction2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Introduction2(QWidget *parent = nullptr);
    ~Introduction2();

private:
    Ui::Introduction2 *ui;
};

#endif // INTRODUCTION2_H
