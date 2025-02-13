#ifndef GAUSS_H
#define GAUSS_H

#include <QWidget>
#include <QClipboard>
#include <QApplication>
#include <boost/multiprecision/cpp_int.hpp>
#include <Eigen/Dense>

namespace Ui {
class Gauss;
}

class Gauss : public QWidget
{
    Q_OBJECT

public:
    Gauss(QWidget *parent = nullptr);
    ~Gauss();
    void setClipboard(QClipboard *clip) {clipboard = clip;}

private slots:

    void on_pushButton_tex_clicked();

    void on_pushButton_ref_clicked();
    void on_pushButton_rref_clicked();

    void on_pushButton_copy_clicked();
    void on_pushButton_copy_tex_clicked();


private:
    Ui::Gauss *ui;
    QClipboard *clipboard;
};

#endif // GAUSS_H
