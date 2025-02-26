#include "et_history_window.h"
#include "ui_et_history_window.h"

#include <compatibility.h>

et_history_window::et_history_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::et_history_window)
{
    this->setWindowFlag(Qt::Window);
    ui->setupUi(this);
}

et_history_window::~et_history_window()
{
    delete ui;
}

void et_history_window::showHistory() const{
    ui->textBrowser->clear();
    ui->textBrowser->append(
        fromHistoryToQString(e_history)
    );
}
