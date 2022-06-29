#ifndef SAVE_REQUEST_H
#define SAVE_REQUEST_H
#include "tmpwindow.h"
#include <QWidget>

namespace Ui {
class save_request;
}

class save_request : public QWidget
{
    Q_OBJECT

public:
    explicit save_request(int num,QWidget *parent = nullptr,TmpWindow *n = nullptr);
    ~save_request();
    TmpWindow *now;
    int num1;
private slots:
    void on_Yesbutton_clicked();

    void on_NoButton_clicked();

private:
    Ui::save_request *ui;
};

#endif // SAVE_REQUEST_H
