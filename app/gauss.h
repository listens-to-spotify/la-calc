#ifndef GAUSS_H
#define GAUSS_H

#include <QWidget>
#include <QClipboard>
#include <QApplication>
#include <matrix.h>
#include <rational.h>
#include <QDateTime>
#include <fstream>

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

    void setLogFile(std::ofstream *log) {logFile = log;}
    void logError(const std::exception &e, const QString &context);


private slots:

    void on_pushButton_tex_clicked();

    void on_pushButton_ref_clicked();
    void on_pushButton_rref_clicked();

    void on_pushButton_copy_clicked();
    void on_pushButton_copy_tex_clicked();


private:
    Ui::Gauss *ui;
    QClipboard *clipboard;

    std::ofstream *logFile;
};

#endif // GAUSS_H
