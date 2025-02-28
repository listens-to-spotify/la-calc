#include <mainwindow/mainwindow.h>
#include "ui_mainwindow.h"

#include <iostream>
#include <compatibility.h>

// Default Constructor & Deconstructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sleWindow(nullptr)
    , GaussWindow(nullptr)
    , SymGaussWindow(nullptr)
{
    ui->setupUi(this);
    clipboard = QApplication::clipboard();

    connect(ui->actionSystem_of_Equations, &QAction::triggered, this, &MainWindow::openSleWindow);
    connect(ui->actionGaussian_Elimination, &QAction::triggered, this, &MainWindow::openGaussWindow);
    connect(ui->actionSymmetric_Gauss, &QAction::triggered, this, &MainWindow::openSymGaussWindow);

    logFile.open(".logs.txt", std::ofstream::out | std::ofstream::trunc);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file!" << std::endl;
    }
}

MainWindow::~MainWindow()
{
    if (logFile.is_open()) {
        logFile.close();
    }
    delete ui;
}

void MainWindow::openSymGaussWindow()
{
    if (!SymGaussWindow) {
        SymGaussWindow = new symmetric_gauss(this);
    }
    SymGaussWindow->setClipboard(clipboard);
    SymGaussWindow->setLogFile(&logFile);
    SymGaussWindow->setFixedSize(640, 480);
    SymGaussWindow->show();
}

void MainWindow::openSleWindow()
{
    if (!sleWindow) {
        sleWindow = new sle(this);
    }
    sleWindow->setClipboard(clipboard);
    sleWindow->setLogFile(&logFile);
    sleWindow->setFixedSize(640, 480);
    sleWindow->show();
}

void MainWindow::openGaussWindow()
{
    if (!GaussWindow) {
        GaussWindow = new Gauss(this);
    }
    GaussWindow->setClipboard(clipboard);
    GaussWindow->setLogFile(&logFile);
    GaussWindow->setFixedSize(640, 480);
    GaussWindow->show();
}

void MainWindow::on_pushButton_det_A_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        ui->textBrowser_result->setPlainText(
            fromRationalToQString(M.det())
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_det_A_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_det_B_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        ui->textBrowser_result->setPlainText(
            fromRationalToQString(M.det())
            );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_det_B_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_inverse_A_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.inverse())
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_inverse_A_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
void MainWindow::on_pushButton_inverse_B_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        if (M.rows() != M.cols()) {
            throw NotSquareMatrixException();
        }

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.inverse())
            );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_inverse_B_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_rank_A_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        ui->textBrowser_result->setPlainText(
            QString::number(M.rank())
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_rank_A_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}


void MainWindow::on_pushButton_rank_B_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        ui->textBrowser_result->setPlainText(
            QString::number(M.rank())
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_rank_B_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_transpose_A_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.transpose())
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_transpose_A_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_transpose_B_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.transpose())
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_transpose_B_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_power_A_clicked()
{
    unsigned int power = ui->spinBox_power_A->value();
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.pow(power))
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_power_A_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_power_B_clicked()
{
    const unsigned int power = ui->spinBox_power_B->value();
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M.pow(power))
            );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_power_B_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_multiply_A_clicked()
{
    const auto coef = ui->spinBox_multiply_A->value();
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M * coef)
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_multiply_A_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
void MainWindow::on_pushButton_multiply_B_clicked()
{
    const auto coef = ui->spinBox_multiply_B->value();
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(M * coef)
            );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_multiply_B_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_plus_clicked()
{
    try {
        Matrix<Rational<int64_t>> A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        Matrix<Rational<int64_t>> B = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(A + B)
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_plus_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_minus_clicked()
{
    try {
        Matrix<Rational<int64_t>> A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        Matrix<Rational<int64_t>> B = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(A - B)
            );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_minus_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_mult_clicked()
{
    try {
        Matrix<Rational<int64_t>> A = fromQStringToMatrix(ui->plainTextEdit_A->toPlainText());
        Matrix<Rational<int64_t>> B = fromQStringToMatrix(ui->plainTextEdit_B->toPlainText());

        ui->textBrowser_result->setPlainText(
            fromMatrixToQString(A * B)
            );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_mult_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_switch_clicked()
{
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
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(ui->textBrowser_result->toPlainText());

        QString text_to_copy = fromMatrixToQStringTex(M);
        clipboard->setText(text_to_copy);
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_copy_tex_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_tex_A_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(clipboard->text());

        ui->plainTextEdit_A->setPlainText(
            fromMatrixToQString(M)
        );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_tex_A_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::on_pushButton_tex_B_clicked()
{
    try {
        Matrix<Rational<int64_t>> M = fromQStringToMatrix(clipboard->text());

        ui->plainTextEdit_B->setPlainText(
            fromMatrixToQString(M)
            );
    } catch (const std::exception &e) {
        logError(e, "on_pushButton_tex_B_clicked");
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void MainWindow::logError(const std::exception &e, const QString &context) {
    if (logFile.is_open()) {
        QDateTime current = QDateTime::currentDateTime();
        logFile << "[" << current.toString("yyyy-MM-dd HH:mm:ss").toStdString() << "] :: "
                << "MainWindow"
                << "ERROR in " << context.toStdString() << " - "
                << "Type: " << typeid(e).name() << ", Message: " << e.what() << "\n";
    }
}
