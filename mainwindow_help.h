#pragma once
#ifndef MAINWINDOW_HELP_H
#define MAINWINDOW_HELP_H

#include <QMainWindow>

namespace Ui {
class MainWindow_help;
}


class MainWindow_help : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow_help(QWidget *parent = nullptr);
        ~MainWindow_help();
    private:
        Ui::MainWindow_help *ui;
};
#endif // MAINWINDOW_H
