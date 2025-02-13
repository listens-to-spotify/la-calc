#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include "my_functions.h"

// Default Constructor & Deconstructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sleWindow(nullptr)
    , GaussWindow(nullptr)
{
    ui->setupUi(this);
    clipboard = QApplication::clipboard();
    connect(ui->actionSystem_of_Equations, &QAction::triggered, this, &MainWindow::openSleWindow);
    connect(ui->actionGaussian_Elimination, &QAction::triggered, this, &MainWindow::openGaussWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSleWindow() {
    if (!sleWindow) {
        sleWindow = new sle(this);
    }
    sleWindow->setClipboard(clipboard);
    sleWindow->show();
}

void MainWindow::openGaussWindow() {
    if (!GaussWindow) {
        GaussWindow = new Gauss(this);
    }
    GaussWindow->setClipboard(clipboard);
    GaussWindow->show();
}

void MainWindow::on_pushButton_det_A_clicked()
{
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        int swaps = 0;
        gaussianElimination(M, swaps);
        Rational result = ((swaps % 2) ? -1 : 1);

        result *= M.diagonal().prod();

        ui->textBrowser_result->setPlainText(
            fromRationalToQString(result)
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_det_B_clicked()
{
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        int swaps = 0;
        gaussianElimination(M, swaps);
        Rational result = ((swaps % 2) ? -1 : 1);

        result *= M.diagonal().prod();

        ui->textBrowser_result->setPlainText(
            fromRationalToQString(result)
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_inverse_A_clicked()
{
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.inverse())
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}
void MainWindow::on_pushButton_inverse_B_clicked()
{
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.inverse())
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_rank_A_clicked()
{
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        Eigen::FullPivLU<Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic>> lu_decomp(M);
        int rank = lu_decomp.rank();
        ui->textBrowser_result->setPlainText(
            QString::number(rank)
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}


void MainWindow::on_pushButton_rank_B_clicked()
{
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());
        Eigen::FullPivLU<Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic>> lu_decomp(M);
        int rank = lu_decomp.rank();
        ui->textBrowser_result->setPlainText(
            QString::number(rank)
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_transpose_A_clicked() {
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.transpose())
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_transpose_B_clicked() {
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.transpose())
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_power_A_clicked()
{
    const unsigned int power = ui->spinBox_power_A->value();
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(matrixPower(M, power))
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_power_B_clicked()
{
    const unsigned power = ui->spinBox_power_B->value();
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(matrixPower(M, power))
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_multiply_A_clicked()
{
    const signed int coef = ui->spinBox_multiply_A->value();
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M * coef)
            );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}
void MainWindow::on_pushButton_multiply_B_clicked()
{
    const signed int coef = ui->spinBox_multiply_B->value();
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
        M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());
        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M * coef)
            );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_plus_clicked() {
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> A;
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> B;
        A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        B = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        if (A.rows() != B.rows() || A.cols() != B.cols()) {
            throw InvalidMatrixSizesException();
        }

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(A + B)
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_minus_clicked() {
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> A;
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> B;
        A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        B = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        if (A.rows() != B.rows() || A.cols() != B.cols()) {
            throw InvalidMatrixSizesException();
        }

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(A - B)
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_mult_clicked() {
    try {
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> A;
        Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> B;
        A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        B = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        if (A.cols() != B.rows()) {
            throw InvalidMatrixSizesException();
        }

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(A * B)
        );
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }
}

void MainWindow::on_pushButton_switch_clicked() {
    const QString left = ui->plainTextEdit_A->toPlainText();
    const QString right = ui->plainTextEdit_B->toPlainText();

    ui->plainTextEdit_A->setPlainText(right);
    ui->plainTextEdit_B->setPlainText(left);
}

void MainWindow::on_pushButton_to_A_clicked()
{
    ui->plainTextEdit_A->setPlainText("");
    ui->plainTextEdit_A->setPlainText(ui->textBrowser_result->toPlainText());
}

void MainWindow::on_pushButton_to_B_clicked()
{
    ui->plainTextEdit_B->setPlainText("");
    ui->plainTextEdit_B->setPlainText(ui->textBrowser_result->toPlainText());
}

void MainWindow::on_pushButton_copy_clicked()
{
    const QString text_to_copy = ui->textBrowser_result->toPlainText();
    clipboard->setText(text_to_copy);
}

void MainWindow::on_pushButton_copy_tex_clicked()
{
    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
    try {
        M = fromQStringToMatrix(ui->textBrowser_result->toPlainText());
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }

    QString text_to_copy = fromMatrixToQStringTex(M);
    clipboard->setText(text_to_copy);
}

void MainWindow::on_pushButton_tex_A_clicked()
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

void MainWindow::on_pushButton_tex_B_clicked()
{
    Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic> M;
    try {
        M = fromQStringToMatrix(clipboard->text());
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return;
    }

    ui->plainTextEdit_B->setPlainText(
        fromMatrixToQString(M)
    );
}

