#include "mainwindow.h"
#include "mainwindow2.h"
#include "mainwindow_help.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow * w=new MainWindow;
    w->show();
    return a.exec();
}
