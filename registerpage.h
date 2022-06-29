#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QDialog>

namespace Ui {
class Registerpage;
}

class Registerpage : public QDialog
{
    Q_OBJECT

public:
    explicit Registerpage(QWidget *parent = nullptr);
    ~Registerpage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Registerpage *ui;
};

#endif // REGISTERPAGE_H
