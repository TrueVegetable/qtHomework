#ifndef HINT_H
#define HINT_H

#include <QMainWindow>
#include "mainwindow2.h"
#include "ui_mainwindow2.h"

namespace Ui {
class Hint;
}

class Hint : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hint(QWidget *parent = nullptr);
    ~Hint();
    void gotthis(); //点击按钮关掉界面

private:
    Ui::Hint *ui;
};

#endif // HINT_H
