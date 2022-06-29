#ifndef MAINWINDOW1_2_H
#define MAINWINDOW1_2_H

#include <QMainWindow>
#include <cstring>

namespace Ui {
class MainWindow1_2;
}

class MainWindow1_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1_2(std::string name, QWidget *parent = nullptr);
    ~MainWindow1_2();
    void read_archive(std::string usrname,int num);
    std::string filename;

private slots:
    void on_NGbtm_clicked();

    void on_RS1btm_clicked();

    void on_CS1btm_clicked();

    void on_RS2btm_clicked();

    void on_CS2btm_clicked();

private:
    Ui::MainWindow1_2 *ui;
};

#endif // MAINWINDOW1_2_H
