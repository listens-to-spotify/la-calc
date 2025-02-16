#ifndef SLE_H
#define SLE_H

#include <QWidget>
#include <QClipboard>
#include <QApplication>
#include <matrix.h>
#include <rational.h>
#include <QDateTime>
#include <fstream>

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
    void setLogFile(std::ofstream *log) {logFile = log;}

    void logError(const std::exception &e, const QString &context);

private slots:
    void on_pushButton_tex_clicked();

    void on_pushButton_solve_clicked();

    void on_pushButton_copy_A_clicked();
    void on_pushButton_copy_tex_A_clicked();

    void on_pushButton_copy_b_clicked();
    void on_pushButton_copy_tex_b_clicked();

    void on_pushButoon_copy_tex_Ab_clicked();

private:
    Ui::sle *ui;
    QClipboard *clipboard;

    std::ofstream *logFile;
};

#endif // SLE_H
