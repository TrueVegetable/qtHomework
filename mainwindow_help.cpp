#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainwindow_help.h"
#include "ui_mainwindow_help.h"

MainWindow_help::MainWindow_help(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_help)
{
    ui->setupUi(this);
}

MainWindow_help::~MainWindow_help()
{
    delete ui;
}
