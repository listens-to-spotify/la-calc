#ifndef SLE_H
#define SLE_H

#include <QWidget>
#include <QClipboard>
#include <QApplication>
#include <boost/multiprecision/cpp_int.hpp>
#include <Eigen/Dense>

namespace Ui {
class sle;
}

class sle : public QWidget
{
    Q_OBJECT

public:
    sle(QWidget *parent = nullptr);
    ~sle();
    void setClipboard(QClipboard *clip) {clipboard = clip;}

private slots:
    void on_pushButton_tex_clicked();

    void on_pushButton_solve_clicked();

    void on_pushButton_copy_A_clicked();
    void on_pushButton_copy_tex_A_clicked();

    void on_pushButton_copy_b_clicked();
    void on_pushButton_copy_tex_b_clicked();

private:
    Ui::sle *ui;
    QClipboard *clipboard;
};

#endif // SLE_H
