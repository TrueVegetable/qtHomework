#ifndef TMPWINDOW_H
#define TMPWINDOW_H

#include <QMainWindow>
#include "mainwindow2.h"
#include "ui_mainwindow2.h"

namespace Ui {
class TmpWindow;
}

class TmpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TmpWindow(QWidget *parent = nullptr,MainWindow2 *n = nullptr); //初始化要加入上一个界面的指针，在点击返回主菜单时全部关闭
    ~TmpWindow();
    MainWindow2 *now;
    void t_quit();
    void t_save_quit1();
    void t_save_quit2();
    void re_save_quit(int num);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
private slots:


private:
    Ui::TmpWindow *ui;
};

#endif // TMPWINDOW_H
