#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <sle-window/sle.h>
#include <gauss-window/gauss.h>
#include <sym-gauss-window/symmetric_gauss.h>

#include <QClipboard>
#include <QMainWindow>
#include <QApplication>
#include <matrix.h>
#include <rational.h>
#include <QDateTime>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QClipboard *clipboard;
    void logError(const std::exception &e, const QString &context);

private slots:
    void openSymGaussWindow();
    void openSleWindow();
    void openGaussWindow();

    void on_pushButton_det_A_clicked();
    void on_pushButton_det_B_clicked();

    void on_pushButton_inverse_A_clicked();
    void on_pushButton_inverse_B_clicked();

    void on_pushButton_rank_A_clicked();
    void on_pushButton_rank_B_clicked();

    void on_pushButton_transpose_A_clicked();
    void on_pushButton_transpose_B_clicked();

    void on_pushButton_power_A_clicked();
    void on_pushButton_power_B_clicked();

    void on_pushButton_multiply_A_clicked();
    void on_pushButton_multiply_B_clicked();


    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_mult_clicked();
    void on_pushButton_switch_clicked();

    void on_pushButton_to_A_clicked();
    void on_pushButton_to_B_clicked();

    void on_pushButton_copy_clicked();
    void on_pushButton_copy_tex_clicked();

    void on_pushButton_tex_A_clicked();
    void on_pushButton_tex_B_clicked();

private:
    Ui::MainWindow *ui;
    sle *sleWindow;
    Gauss *GaussWindow;
    symmetric_gauss *SymGaussWindow;

    std::ofstream logFile;
};
#endif // MAINWINDOW_H
