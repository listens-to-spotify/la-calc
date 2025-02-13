#include "gauss.h"
#include "ui_gauss.h"

#include <iostream>
#include "my_functions.h"

Gauss::Gauss(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Gauss)
{
    this->setWindowFlags(Qt::Window);
    ui->setupUi(this);
}

Gauss::~Gauss()
{
    delete ui;
}

void Gauss::on_pushButton_tex_clicked()
{
    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
    try {
        M = fromQStringToMatrix(clipboard->text());
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }

    ui->plainTextEdit_A->setPlainText(
        fromMatrixToQString(M)
    );
}

void Gauss::on_pushButton_ref_clicked()
{
    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> A;
    try {
        A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText()); 
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }

    int x = 0;
    gaussianElimination(A, x);

    ui->textBrowser_result_A->setPlainText(
        fromMatrixToQString(A)
    );
}

void Gauss::on_pushButton_rref_clicked()
{
    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> A;
    try {
        A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }

    int x = 0;
    ExpandedGaussianElimination(A, x);

    ui->textBrowser_result_A->setPlainText(
        fromMatrixToQString(A)
    );
}

void Gauss::on_pushButton_copy_clicked()
{
    const QString text_to_copy = ui->textBrowser_result_A->toPlainText();
    clipboard->setText(text_to_copy);
}

void Gauss::on_pushButton_copy_tex_clicked()
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
