#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();

    void on_regisButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
