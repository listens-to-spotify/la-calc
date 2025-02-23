/********************************************************************************
** Form generated from reading UI file 'symmetric_gauss.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMMETRIC_GAUSS_H
#define UI_SYMMETRIC_GAUSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_symmetric_gauss
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_tex;
    QPushButton *pushButton_solve;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit_A;
    QPlainTextEdit *plainTextEdit_b;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_copy_A;
    QPushButton *pushButton_copy_tex_A;
    QPushButton *pushButton_copy_tex_Ab;
    QPushButton *pushButton_copy_tex_b;
    QPushButton *pushButton_copy_b;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *textBrowser_result_A;
    QTextBrowser *textBrowser_result_b;
    QTextBrowser *textBrowser_is_correct;

    void setupUi(QWidget *symmetric_gauss)
    {
        if (symmetric_gauss->objectName().isEmpty())
            symmetric_gauss->setObjectName("symmetric_gauss");
        symmetric_gauss->resize(640, 480);
        layoutWidget = new QWidget(symmetric_gauss);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(90, 199, 451, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_tex = new QPushButton(layoutWidget);
        pushButton_tex->setObjectName("pushButton_tex");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_tex->sizePolicy().hasHeightForWidth());
        pushButton_tex->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_tex);

        pushButton_solve = new QPushButton(layoutWidget);
        pushButton_solve->setObjectName("pushButton_solve");
        sizePolicy.setHeightForWidth(pushButton_solve->sizePolicy().hasHeightForWidth());
        pushButton_solve->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_solve);

        layoutWidget_2 = new QWidget(symmetric_gauss);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(90, 20, 451, 171));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit_A = new QPlainTextEdit(layoutWidget_2);
        plainTextEdit_A->setObjectName("plainTextEdit_A");
        plainTextEdit_A->setPlaceholderText(QString::fromUtf8("A"));

        horizontalLayout->addWidget(plainTextEdit_A);

        plainTextEdit_b = new QPlainTextEdit(layoutWidget_2);
        plainTextEdit_b->setObjectName("plainTextEdit_b");

        horizontalLayout->addWidget(plainTextEdit_b);

        layoutWidget_3 = new QWidget(symmetric_gauss);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(90, 420, 451, 30));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButton_copy_A = new QPushButton(layoutWidget_3);
        pushButton_copy_A->setObjectName("pushButton_copy_A");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_copy_A->sizePolicy().hasHeightForWidth());
        pushButton_copy_A->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(pushButton_copy_A);

        pushButton_copy_tex_A = new QPushButton(layoutWidget_3);
        pushButton_copy_tex_A->setObjectName("pushButton_copy_tex_A");
        sizePolicy1.setHeightForWidth(pushButton_copy_tex_A->sizePolicy().hasHeightForWidth());
        pushButton_copy_tex_A->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(pushButton_copy_tex_A);

        pushButton_copy_tex_Ab = new QPushButton(layoutWidget_3);
        pushButton_copy_tex_Ab->setObjectName("pushButton_copy_tex_Ab");
        sizePolicy1.setHeightForWidth(pushButton_copy_tex_Ab->sizePolicy().hasHeightForWidth());
        pushButton_copy_tex_Ab->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(pushButton_copy_tex_Ab);

        pushButton_copy_tex_b = new QPushButton(layoutWidget_3);
        pushButton_copy_tex_b->setObjectName("pushButton_copy_tex_b");
        sizePolicy1.setHeightForWidth(pushButton_copy_tex_b->sizePolicy().hasHeightForWidth());
        pushButton_copy_tex_b->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(pushButton_copy_tex_b);

        pushButton_copy_b = new QPushButton(layoutWidget_3);
        pushButton_copy_b->setObjectName("pushButton_copy_b");
        sizePolicy1.setHeightForWidth(pushButton_copy_b->sizePolicy().hasHeightForWidth());
        pushButton_copy_b->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(pushButton_copy_b);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        layoutWidget_4 = new QWidget(symmetric_gauss);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(91, 240, 451, 170));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        textBrowser_result_A = new QTextBrowser(layoutWidget_4);
        textBrowser_result_A->setObjectName("textBrowser_result_A");
        textBrowser_result_A->setPlaceholderText(QString::fromUtf8("A'"));

        horizontalLayout_3->addWidget(textBrowser_result_A);

        textBrowser_result_b = new QTextBrowser(layoutWidget_4);
        textBrowser_result_b->setObjectName("textBrowser_result_b");

        horizontalLayout_3->addWidget(textBrowser_result_b);

        textBrowser_is_correct = new QTextBrowser(symmetric_gauss);
        textBrowser_is_correct->setObjectName("textBrowser_is_correct");
        textBrowser_is_correct->setGeometry(QRect(550, 200, 83, 31));

        retranslateUi(symmetric_gauss);

        QMetaObject::connectSlotsByName(symmetric_gauss);
    } // setupUi

    void retranslateUi(QWidget *symmetric_gauss)
    {
        symmetric_gauss->setWindowTitle(QCoreApplication::translate("symmetric_gauss", "Symmetric Gauss", nullptr));
        pushButton_tex->setText(QCoreApplication::translate("symmetric_gauss", "Paste LaTeX code", nullptr));
        pushButton_solve->setText(QCoreApplication::translate("symmetric_gauss", "Apply", nullptr));
        plainTextEdit_b->setPlaceholderText(QCoreApplication::translate("symmetric_gauss", "C", nullptr));
        pushButton_copy_A->setText(QCoreApplication::translate("symmetric_gauss", "Copy array", nullptr));
        pushButton_copy_tex_A->setText(QCoreApplication::translate("symmetric_gauss", "Copy LaTeX", nullptr));
        pushButton_copy_tex_Ab->setText(QCoreApplication::translate("symmetric_gauss", "Copy LaTeX", nullptr));
        pushButton_copy_tex_b->setText(QCoreApplication::translate("symmetric_gauss", "Copy LaTeX", nullptr));
        pushButton_copy_b->setText(QCoreApplication::translate("symmetric_gauss", "Copy array", nullptr));
        textBrowser_result_b->setPlaceholderText(QCoreApplication::translate("symmetric_gauss", "C'", nullptr));
        textBrowser_is_correct->setPlaceholderText(QCoreApplication::translate("symmetric_gauss", "IsCorrect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class symmetric_gauss: public Ui_symmetric_gauss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMMETRIC_GAUSS_H
