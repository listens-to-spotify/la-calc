/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSystem_of_Equations;
    QAction *actionGaussian_Elimination;
    QAction *actionExp_Gaussian_Elimination;
    QAction *actionSymmetric_Gauss;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_B;
    QPlainTextEdit *plainTextEdit_B;
    QGridLayout *gridLayout_B;
    QPushButton *pushButton_transpose_B;
    QPushButton *pushButton_rank_B;
    QPushButton *pushButton_det_B;
    QPushButton *pushButton_inverse_B;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_A;
    QPlainTextEdit *plainTextEdit_A;
    QGridLayout *gridLayout_A;
    QPushButton *pushButton_transpose_A;
    QPushButton *pushButton_inverse_A;
    QPushButton *pushButton_rank_A;
    QPushButton *pushButton_det_A;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_operators;
    QPushButton *pushButton_switch;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_mult;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_result;
    QGridLayout *gridLayout;
    QPushButton *pushButton_to_A;
    QPushButton *pushButton_copy_tex;
    QPushButton *pushButton_copy;
    QPushButton *pushButton_to_B;
    QPushButton *pushButton_tex_A;
    QPushButton *pushButton_tex_B;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_power_B;
    QPushButton *pushButton_multiply_B;
    QSpinBox *spinBox_power_B;
    QSpinBox *spinBox_multiply_B;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_power_A;
    QSpinBox *spinBox_power_A;
    QPushButton *pushButton_multiply_A;
    QSpinBox *spinBox_multiply_A;
    QMenuBar *menubar;
    QMenu *menuCalculator;
    QMenu *menuAlgorithms;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(875, 671);
        actionSystem_of_Equations = new QAction(MainWindow);
        actionSystem_of_Equations->setObjectName("actionSystem_of_Equations");
        actionGaussian_Elimination = new QAction(MainWindow);
        actionGaussian_Elimination->setObjectName("actionGaussian_Elimination");
        actionExp_Gaussian_Elimination = new QAction(MainWindow);
        actionExp_Gaussian_Elimination->setObjectName("actionExp_Gaussian_Elimination");
        actionSymmetric_Gauss = new QAction(MainWindow);
        actionSymmetric_Gauss->setObjectName("actionSymmetric_Gauss");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(600, 30, 221, 241));
        verticalLayout_B = new QVBoxLayout(layoutWidget);
        verticalLayout_B->setObjectName("verticalLayout_B");
        verticalLayout_B->setContentsMargins(0, 0, 0, 0);
        plainTextEdit_B = new QPlainTextEdit(layoutWidget);
        plainTextEdit_B->setObjectName("plainTextEdit_B");

        verticalLayout_B->addWidget(plainTextEdit_B);

        gridLayout_B = new QGridLayout();
        gridLayout_B->setObjectName("gridLayout_B");
        pushButton_transpose_B = new QPushButton(layoutWidget);
        pushButton_transpose_B->setObjectName("pushButton_transpose_B");

        gridLayout_B->addWidget(pushButton_transpose_B, 1, 1, 1, 1);

        pushButton_rank_B = new QPushButton(layoutWidget);
        pushButton_rank_B->setObjectName("pushButton_rank_B");

        gridLayout_B->addWidget(pushButton_rank_B, 1, 0, 1, 1);

        pushButton_det_B = new QPushButton(layoutWidget);
        pushButton_det_B->setObjectName("pushButton_det_B");

        gridLayout_B->addWidget(pushButton_det_B, 0, 0, 1, 1);

        pushButton_inverse_B = new QPushButton(layoutWidget);
        pushButton_inverse_B->setObjectName("pushButton_inverse_B");

        gridLayout_B->addWidget(pushButton_inverse_B, 0, 1, 1, 1);


        verticalLayout_B->addLayout(gridLayout_B);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(50, 30, 221, 241));
        verticalLayout_A = new QVBoxLayout(layoutWidget1);
        verticalLayout_A->setObjectName("verticalLayout_A");
        verticalLayout_A->setContentsMargins(0, 0, 0, 0);
        plainTextEdit_A = new QPlainTextEdit(layoutWidget1);
        plainTextEdit_A->setObjectName("plainTextEdit_A");

        verticalLayout_A->addWidget(plainTextEdit_A);

        gridLayout_A = new QGridLayout();
        gridLayout_A->setObjectName("gridLayout_A");
        pushButton_transpose_A = new QPushButton(layoutWidget1);
        pushButton_transpose_A->setObjectName("pushButton_transpose_A");

        gridLayout_A->addWidget(pushButton_transpose_A, 1, 1, 1, 1);

        pushButton_inverse_A = new QPushButton(layoutWidget1);
        pushButton_inverse_A->setObjectName("pushButton_inverse_A");

        gridLayout_A->addWidget(pushButton_inverse_A, 0, 1, 1, 1);

        pushButton_rank_A = new QPushButton(layoutWidget1);
        pushButton_rank_A->setObjectName("pushButton_rank_A");

        gridLayout_A->addWidget(pushButton_rank_A, 1, 0, 1, 1);

        pushButton_det_A = new QPushButton(layoutWidget1);
        pushButton_det_A->setObjectName("pushButton_det_A");

        gridLayout_A->addWidget(pushButton_det_A, 0, 0, 1, 1);


        verticalLayout_A->addLayout(gridLayout_A);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(390, 30, 101, 124));
        verticalLayout_operators = new QVBoxLayout(layoutWidget2);
        verticalLayout_operators->setObjectName("verticalLayout_operators");
        verticalLayout_operators->setContentsMargins(0, 0, 0, 0);
        pushButton_switch = new QPushButton(layoutWidget2);
        pushButton_switch->setObjectName("pushButton_switch");

        verticalLayout_operators->addWidget(pushButton_switch);

        pushButton_plus = new QPushButton(layoutWidget2);
        pushButton_plus->setObjectName("pushButton_plus");

        verticalLayout_operators->addWidget(pushButton_plus);

        pushButton_minus = new QPushButton(layoutWidget2);
        pushButton_minus->setObjectName("pushButton_minus");

        verticalLayout_operators->addWidget(pushButton_minus);

        pushButton_mult = new QPushButton(layoutWidget2);
        pushButton_mult->setObjectName("pushButton_mult");

        verticalLayout_operators->addWidget(pushButton_mult);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(330, 310, 221, 241));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_result = new QTextBrowser(layoutWidget3);
        textBrowser_result->setObjectName("textBrowser_result");

        verticalLayout->addWidget(textBrowser_result);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_to_A = new QPushButton(layoutWidget3);
        pushButton_to_A->setObjectName("pushButton_to_A");

        gridLayout->addWidget(pushButton_to_A, 0, 0, 1, 1);

        pushButton_copy_tex = new QPushButton(layoutWidget3);
        pushButton_copy_tex->setObjectName("pushButton_copy_tex");

        gridLayout->addWidget(pushButton_copy_tex, 1, 1, 1, 1);

        pushButton_copy = new QPushButton(layoutWidget3);
        pushButton_copy->setObjectName("pushButton_copy");

        gridLayout->addWidget(pushButton_copy, 1, 0, 1, 1);

        pushButton_to_B = new QPushButton(layoutWidget3);
        pushButton_to_B->setObjectName("pushButton_to_B");

        gridLayout->addWidget(pushButton_to_B, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton_tex_A = new QPushButton(centralwidget);
        pushButton_tex_A->setObjectName("pushButton_tex_A");
        pushButton_tex_A->setGeometry(QRect(50, 350, 221, 27));
        pushButton_tex_B = new QPushButton(centralwidget);
        pushButton_tex_B->setObjectName("pushButton_tex_B");
        pushButton_tex_B->setGeometry(QRect(600, 350, 221, 27));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(600, 280, 221, 62));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_power_B = new QPushButton(layoutWidget_2);
        pushButton_power_B->setObjectName("pushButton_power_B");

        gridLayout_3->addWidget(pushButton_power_B, 0, 0, 1, 1);

        pushButton_multiply_B = new QPushButton(layoutWidget_2);
        pushButton_multiply_B->setObjectName("pushButton_multiply_B");

        gridLayout_3->addWidget(pushButton_multiply_B, 1, 0, 1, 1);

        spinBox_power_B = new QSpinBox(layoutWidget_2);
        spinBox_power_B->setObjectName("spinBox_power_B");

        gridLayout_3->addWidget(spinBox_power_B, 0, 1, 1, 1);

        spinBox_multiply_B = new QSpinBox(layoutWidget_2);
        spinBox_multiply_B->setObjectName("spinBox_multiply_B");
        spinBox_multiply_B->setMinimum(-1000);
        spinBox_multiply_B->setMaximum(1000);

        gridLayout_3->addWidget(spinBox_multiply_B, 1, 1, 1, 1);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(50, 280, 221, 62));
        gridLayout_2 = new QGridLayout(layoutWidget4);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_power_A = new QPushButton(layoutWidget4);
        pushButton_power_A->setObjectName("pushButton_power_A");

        gridLayout_2->addWidget(pushButton_power_A, 0, 0, 1, 1);

        spinBox_power_A = new QSpinBox(layoutWidget4);
        spinBox_power_A->setObjectName("spinBox_power_A");

        gridLayout_2->addWidget(spinBox_power_A, 0, 1, 1, 1);

        pushButton_multiply_A = new QPushButton(layoutWidget4);
        pushButton_multiply_A->setObjectName("pushButton_multiply_A");

        gridLayout_2->addWidget(pushButton_multiply_A, 1, 0, 1, 1);

        spinBox_multiply_A = new QSpinBox(layoutWidget4);
        spinBox_multiply_A->setObjectName("spinBox_multiply_A");
        spinBox_multiply_A->setMinimum(-1000);
        spinBox_multiply_A->setMaximum(1000);

        gridLayout_2->addWidget(spinBox_multiply_A, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 875, 23));
        menuCalculator = new QMenu(menubar);
        menuCalculator->setObjectName("menuCalculator");
        menuAlgorithms = new QMenu(menuCalculator);
        menuAlgorithms->setObjectName("menuAlgorithms");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuCalculator->menuAction());
        menuCalculator->addAction(actionSystem_of_Equations);
        menuCalculator->addAction(menuAlgorithms->menuAction());
        menuAlgorithms->addAction(actionGaussian_Elimination);
        menuAlgorithms->addSeparator();
        menuAlgorithms->addAction(actionSymmetric_Gauss);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LA-calculator", nullptr));
        actionSystem_of_Equations->setText(QCoreApplication::translate("MainWindow", "System of Equations", nullptr));
        actionGaussian_Elimination->setText(QCoreApplication::translate("MainWindow", "Gaussian Elimination", nullptr));
        actionExp_Gaussian_Elimination->setText(QCoreApplication::translate("MainWindow", "Exp Gaussian Elimination", nullptr));
        actionSymmetric_Gauss->setText(QCoreApplication::translate("MainWindow", "Symmetric Gauss", nullptr));
        plainTextEdit_B->setPlaceholderText(QString());
        pushButton_transpose_B->setText(QCoreApplication::translate("MainWindow", "Transpose", nullptr));
        pushButton_rank_B->setText(QCoreApplication::translate("MainWindow", "Rank", nullptr));
        pushButton_det_B->setText(QCoreApplication::translate("MainWindow", "Determinant", nullptr));
        pushButton_inverse_B->setText(QCoreApplication::translate("MainWindow", "Inverse", nullptr));
        plainTextEdit_A->setPlaceholderText(QString());
        pushButton_transpose_A->setText(QCoreApplication::translate("MainWindow", "Transpose", nullptr));
        pushButton_inverse_A->setText(QCoreApplication::translate("MainWindow", "Inverse", nullptr));
        pushButton_rank_A->setText(QCoreApplication::translate("MainWindow", "Rank", nullptr));
        pushButton_det_A->setText(QCoreApplication::translate("MainWindow", "Determinant", nullptr));
        pushButton_switch->setText(QCoreApplication::translate("MainWindow", "switch", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "A + B", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "A - B", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "A * B", nullptr));
        pushButton_to_A->setText(QCoreApplication::translate("MainWindow", "Insert into A", nullptr));
        pushButton_copy_tex->setText(QCoreApplication::translate("MainWindow", "Copy LaTeX", nullptr));
        pushButton_copy->setText(QCoreApplication::translate("MainWindow", "Copy array", nullptr));
        pushButton_to_B->setText(QCoreApplication::translate("MainWindow", "Insert into B", nullptr));
        pushButton_tex_A->setText(QCoreApplication::translate("MainWindow", "Paste LaTeX code", nullptr));
        pushButton_tex_B->setText(QCoreApplication::translate("MainWindow", "Paste LaTeX code", nullptr));
        pushButton_power_B->setText(QCoreApplication::translate("MainWindow", "To the power of", nullptr));
        pushButton_multiply_B->setText(QCoreApplication::translate("MainWindow", "Multiply by", nullptr));
        pushButton_power_A->setText(QCoreApplication::translate("MainWindow", "To the power of", nullptr));
        pushButton_multiply_A->setText(QCoreApplication::translate("MainWindow", "Multiply by", nullptr));
        menuCalculator->setTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        menuAlgorithms->setTitle(QCoreApplication::translate("MainWindow", "Algorithms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
