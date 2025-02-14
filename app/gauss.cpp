#include "gauss.h"
#include "ui_gauss.h"

#include <iostream>
#include <compatibility.h>

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
    try {
        Matrix<Rational<int32_t>> A = fromQStringToMatrix(clipboard->text());

        ui->plainTextEdit_A->setPlainText(
            fromMatrixToQString(A)
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_tex_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Gauss::on_pushButton_ref_clicked()
{
    try {
        Matrix<Rational<int32_t>> A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        A.toREF();

        ui->textBrowser_result_A->setPlainText(
            fromMatrixToQString(A)
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_ref_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Gauss::on_pushButton_rref_clicked()
{
    try {
        Matrix<Rational<int32_t>> A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        A.toRREF();

        ui->textBrowser_result_A->setPlainText(
            fromMatrixToQString(A)
            );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_rref_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Gauss::on_pushButton_copy_clicked()
{
    const QString text_to_copy = ui->textBrowser_result_A->toPlainText();
    clipboard->setText(text_to_copy);
}

void Gauss::on_pushButton_copy_tex_clicked()
{
    try {
        Matrix<Rational<int32_t>> A = fromQStringToMatrix(ui->textBrowser_result_A->toPlainText());

        QString text_to_copy = fromMatrixToQStringTex(A);
        clipboard->setText(text_to_copy);
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_copy_tex_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Gauss::logError(const std::exception &e, const QString &context) {
    if ((*logFile).is_open()) {
        QDateTime current = QDateTime::currentDateTime();
        (*logFile) << "[" << current.toString("yyyy-MM-dd HH:mm:ss").toStdString() << "] :: "
                   << "GaussWindow"
                   << "ERROR in " << context.toStdString() << " - "
                   << "Type: " << typeid(e).name() << ", Message: " << e.what() << "\n";
    }
}
