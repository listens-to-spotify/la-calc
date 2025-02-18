#include "symmetric_gauss.h"
#include "ui_symmetric_gauss.h"

#include <iostream>
#include <compatibility.h>

symmetric_gauss::symmetric_gauss(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::symmetric_gauss)
{
    this->setWindowFlag(Qt::Window);
    ui->setupUi(this);
}

symmetric_gauss::~symmetric_gauss()
{
    delete ui;
}

void symmetric_gauss::on_pushButton_tex_clicked()
{
    try {
        Matrix<Rational<int32_t>> M = fromQStringToMatrix(clipboard->text());

        if (2 * M.rows() == M.cols()) {
            ui->plainTextEdit_A->setPlainText(
                fromMatrixToQString(M.getLeftCols(M.rows()))
            );

            ui->plainTextEdit_b->setPlainText(
                fromMatrixToQString(M.getRightCols(M.rows()))
            );
        } else {
            ui->plainTextEdit_A->setPlainText(
                fromMatrixToQString(M.getLeftCols(M.rows()))
            );

            ui->plainTextEdit_b->setPlainText(
                fromMatrixToQString(Identity<Rational<int32_t>>(M.rows()))
            );
        }

    } catch (const std::exception &e) {
        logError(e, "on_pushButton_tex_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void symmetric_gauss::on_pushButton_solve_clicked()
{
    try {
        Matrix<Rational<int32_t>> A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        Matrix<Rational<int32_t>> b = fromQStringToMatrix(ui->plainTextEdit_b->toPlainText());

        A.symmetricGauss(b);

        ui->textBrowser_result_A->setPlainText(
            fromMatrixToQString(A)
            );
        ui->textBrowser_result_b->setPlainText(
            fromMatrixToQString(b)
            );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_solve_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}


void symmetric_gauss::on_pushButton_copy_A_clicked()
{
    const QString text_to_copy = ui->textBrowser_result_A->toPlainText();
    clipboard->setText(text_to_copy);
}

void symmetric_gauss::on_pushButton_copy_tex_A_clicked()
{
    try {
        Matrix<Rational<int32_t>> M = fromQStringToMatrix(ui->textBrowser_result_A->toPlainText());

        QString text_to_copy = fromMatrixToQStringTex(M);
        clipboard->setText(text_to_copy);
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_copy_tex_A_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void symmetric_gauss::on_pushButton_copy_b_clicked()
{
    const QString text_to_copy = ui->textBrowser_result_b->toPlainText();
    clipboard->setText(text_to_copy);
}

void symmetric_gauss::on_pushButton_copy_tex_b_clicked()
{
    try {
        Matrix<Rational<int32_t>> M = fromQStringToMatrix(ui->textBrowser_result_b->toPlainText());

        QString text_to_copy = fromMatrixToQStringTex(M);
        clipboard->setText(text_to_copy);
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_copy_tex_b_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void symmetric_gauss::on_pushButton_copy_tex_Ab_clicked()
{
    try {
        Matrix<Rational<int32_t>> A = fromQStringToMatrix(ui->textBrowser_result_A->toPlainText());
        Matrix<Rational<int32_t>> b = fromQStringToMatrix(ui->textBrowser_result_b->toPlainText());

        QString text_to_copy = fromMatrixToQStringTex(A.joinRight(b));
        clipboard->setText(text_to_copy);
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_copy_tex_Ab_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void symmetric_gauss::logError(const std::exception &e, const QString &context) {
    if ((*logFile).is_open()) {
        QDateTime current = QDateTime::currentDateTime();
        (*logFile) << "[" << current.toString("yyyy-MM-dd HH:mm:ss").toStdString() << "] :: "
                   << "SymGaussWindow"
                   << "ERROR in " << context.toStdString() << " - "
                   << "Type: " << typeid(e).name() << ", Message: " << e.what() << "\n";
    }
}

