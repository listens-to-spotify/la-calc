#include <sle-window/sle.h>
#include "ui_sle.h"

#include <iostream>
#include <compatibility.h>

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
    try {
        Matrix<Rational<int32_t>> M = fromQStringToMatrix(clipboard->text());

        ui->plainTextEdit_A->setPlainText(
            fromMatrixToQString(M.getLeftCols(M.cols() - 1))
        );
        ui->plainTextEdit_b->setPlainText(
            fromMatrixToQString(M.getRightCols(1))
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_tex_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void sle::on_pushButton_solve_clicked()
{
    try {
        Matrix<Rational<int32_t>> A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        Matrix<Rational<int32_t>> b = fromQStringToMatrix(ui->plainTextEdit_b->toPlainText());

        A.toRREF(b);

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


void sle::on_pushButton_copy_A_clicked()
{
    const QString text_to_copy = ui->textBrowser_result_A->toPlainText();
    clipboard->setText(text_to_copy);
}

void sle::on_pushButton_copy_tex_A_clicked()
{
    try {
        Matrix<Rational<int32_t>> M = fromQStringToMatrix(ui->textBrowser_result_A->toPlainText());

        QString text_to_copy = fromMatrixToQStringTex(M);
        clipboard->setText(text_to_copy);
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_copy_A_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void sle::on_pushButton_copy_b_clicked()
{
    const QString text_to_copy = ui->textBrowser_result_b->toPlainText();
    clipboard->setText(text_to_copy);
}

void sle::on_pushButton_copy_tex_b_clicked()
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

void sle::on_pushButton_copy_tex_Ab_clicked()
{
    try {
        Matrix<Rational<int32_t>> A = fromQStringToMatrix(ui->textBrowser_result_A->toPlainText());
        Matrix<Rational<int32_t>> b = fromQStringToMatrix(ui->textBrowser_result_b->toPlainText());

        QString text_to_copy = fromMatrixToQStringTex(A.joinRight(b));
        clipboard->setText(text_to_copy);
    } catch (const std::exception &e) {
        logError(e, "on_pushButoon_copy_tex_Ab_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void sle::logError(const std::exception &e, const QString &context) {
    if ((*logFile).is_open()) {
        QDateTime current = QDateTime::currentDateTime();
        (*logFile) << "[" << current.toString("yyyy-MM-dd HH:mm:ss").toStdString() << "] :: "
                   << "sleWindow"
                   << "ERROR in " << context.toStdString() << " - "
                   << "Type: " << typeid(e).name() << ", Message: " << e.what() << "\n";
    }
}
