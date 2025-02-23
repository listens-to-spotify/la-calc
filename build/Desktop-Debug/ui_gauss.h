/********************************************************************************
** Form generated from reading UI file 'gauss.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSS_H
#define UI_GAUSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gauss
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_copy;
    QPushButton *pushButton_copy_tex;
    QTextBrowser *textBrowser_result_A;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *plainTextEdit_A;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_tex;
    QPushButton *pushButton_ref;
    QPushButton *pushButton_rref;

    void setupUi(QWidget *Gauss)
    {
        if (Gauss->objectName().isEmpty())
            Gauss->setObjectName("Gauss");
        Gauss->resize(640, 480);
        widget = new QWidget(Gauss);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(110, 260, 421, 180));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_copy = new QPushButton(widget);
        pushButton_copy->setObjectName("pushButton_copy");

        horizontalLayout_2->addWidget(pushButton_copy);

        pushButton_copy_tex = new QPushButton(widget);
        pushButton_copy_tex->setObjectName("pushButton_copy_tex");

        horizontalLayout_2->addWidget(pushButton_copy_tex);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        textBrowser_result_A = new QTextBrowser(widget);
        textBrowser_result_A->setObjectName("textBrowser_result_A");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser_result_A->sizePolicy().hasHeightForWidth());
        textBrowser_result_A->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textBrowser_result_A, 0, 0, 1, 1);

        widget1 = new QWidget(Gauss);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(110, 30, 421, 211));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        plainTextEdit_A = new QPlainTextEdit(widget1);
        plainTextEdit_A->setObjectName("plainTextEdit_A");

        gridLayout_2->addWidget(plainTextEdit_A, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_tex = new QPushButton(widget1);
        pushButton_tex->setObjectName("pushButton_tex");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_tex->sizePolicy().hasHeightForWidth());
        pushButton_tex->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_tex);

        pushButton_ref = new QPushButton(widget1);
        pushButton_ref->setObjectName("pushButton_ref");
        sizePolicy1.setHeightForWidth(pushButton_ref->sizePolicy().hasHeightForWidth());
        pushButton_ref->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_ref);

        pushButton_rref = new QPushButton(widget1);
        pushButton_rref->setObjectName("pushButton_rref");
        sizePolicy1.setHeightForWidth(pushButton_rref->sizePolicy().hasHeightForWidth());
        pushButton_rref->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_rref);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(Gauss);

        QMetaObject::connectSlotsByName(Gauss);
    } // setupUi

    void retranslateUi(QWidget *Gauss)
    {
        Gauss->setWindowTitle(QCoreApplication::translate("Gauss", "GaussianElimination", nullptr));
        pushButton_copy->setText(QCoreApplication::translate("Gauss", "Copy array", nullptr));
        pushButton_copy_tex->setText(QCoreApplication::translate("Gauss", "Copy LaTeX", nullptr));
        textBrowser_result_A->setPlaceholderText(QCoreApplication::translate("Gauss", "A'", nullptr));
        plainTextEdit_A->setPlaceholderText(QCoreApplication::translate("Gauss", "A", nullptr));
        pushButton_tex->setText(QCoreApplication::translate("Gauss", "Paste LaTeX code", nullptr));
        pushButton_ref->setText(QCoreApplication::translate("Gauss", "REF", nullptr));
        pushButton_rref->setText(QCoreApplication::translate("Gauss", "RREF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gauss: public Ui_Gauss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSS_H
