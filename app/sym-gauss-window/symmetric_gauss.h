#ifndef SYMMETRIC_GAUSS_H
#define SYMMETRIC_GAUSS_H

#include <et-history-window/et_history_window.h>

#include <QWidget>
#include <QClipboard>
#include <QApplication>
#include <matrix.h>
#include <rational.h>
#include <QDateTime>
#include <fstream>
#include <e_history.h>

namespace Ui {
class symmetric_gauss;
}

class symmetric_gauss : public QWidget
{
    Q_OBJECT

public:
    explicit symmetric_gauss(QWidget *parent = nullptr);
    ~symmetric_gauss();
    void setClipboard(QClipboard *clip) {clipboard = clip;}
    void setLogFile(std::ofstream *log) {logFile = log;}

    void logError(const std::exception &e, const QString &context);


private slots:
    void openMoreWindow();

    void on_pushButton_tex_clicked();

    void on_pushButton_solve_clicked();

    void on_pushButton_copy_A_clicked();
    void on_pushButton_copy_tex_A_clicked();

    void on_pushButton_copy_b_clicked();
    void on_pushButton_copy_tex_b_clicked();

    void on_pushButton_copy_tex_Ab_clicked();
    void on_pushButton_more_clicked();

private:
    Ui::symmetric_gauss *ui;
    QClipboard *clipboard;
    et_history_window *MoreWindow;
    history<Matrix<Rational<int64_t>>> e_history;

    std::ofstream *logFile;
};

#endif // SYMMETRIC_GAUSS_H
