#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include <QMainWindow>
#include "mainwindow2.h"
#include "ui_mainwindow2.h"

namespace Ui {
class Introduction;
}

class Introduction : public QMainWindow
{
    Q_OBJECT

public:
    explicit Introduction(QWidget *parent = nullptr);
    ~Introduction();

private:
    Ui::Introduction *ui;
};

#endif // INTRODUCTION_H
