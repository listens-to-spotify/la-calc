#include "sle.h"
#include "ui_sle.h"

#include <iostream>
#include "my_functions.h"

sle::sle(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sle)
{
    this->setWindowFlags(Qt::Window);
    ui->setupUi(this);
}

sle::~sle()
{
        delete ui;
}

void sle::on_pushButton_tex_clicked()
{
    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
    try {
        M = fromQStringToMatrix(clipboard->text());
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }

    ui->plainTextEdit_A->setPlainText(
        fromMatrixToQString(M.leftCols(M.cols() - 1))
    );
    ui->plainTextEdit_b->setPlainText(
        fromMatrixToQString(M.rightCols(1))
    );
}

void sle::on_pushButton_solve_clicked()
{
    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> A;
    Eigen::Matrix<Rational, Eigen::Dynamic, 1> b;
    try {
        A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        b = fromQStringToMatrix(ui->plainTextEdit_b->toPlainText());
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }

    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> Ab(A.rows(), A.cols() + 1);
    Ab.block(0, 0, A.rows(), A.cols()) = A;
    Ab.col(A.cols()) = b;

    int x = 0;
    ExpandedGaussianElimination(Ab, x);

    A = Ab.leftCols(Ab.cols() - 1);
    b = Ab.rightCols(1);

    ui->textBrowser_result_A->setPlainText(
        fromMatrixToQString(A)
    );
    ui->textBrowser_result_B->setPlainText(
        fromMatrixToQString(b)
    );
}


void sle::on_pushButton_copy_A_clicked()
{
    const QString text_to_copy = ui->textBrowser_result_A->toPlainText();
    clipboard->setText(text_to_copy);
}

void sle::on_pushButton_copy_tex_A_clicked()
{
    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
    try {
        M = fromQStringToMatrix(ui->textBrowser_result_A->toPlainText());
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }

    QString text_to_copy = fromMatrixToQStringTex(M);
    clipboard->setText(text_to_copy);
}

void sle::on_pushButton_copy_b_clicked()
{
    const QString text_to_copy = ui->textBrowser_result_B->toPlainText();
    clipboard->setText(text_to_copy);
}

void sle::on_pushButton_copy_tex_b_clicked()
{
    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
    try {
        M = fromQStringToMatrix(ui->textBrowser_result_B->toPlainText());
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }

    QString text_to_copy = fromMatrixToQStringTex(M);
    clipboard->setText(text_to_copy);
}

