#ifndef ET_HISTORY_WINDOW_H
#define ET_HISTORY_WINDOW_H

#include <QWidget>
#include <QClipboard>
#include <QApplication>
#include <matrix.h>
#include <rational.h>
#include <QDateTime>
#include <e_history.h>

namespace Ui {
class et_history_window;
}

class et_history_window : public QWidget
{
    Q_OBJECT

public:
    explicit et_history_window(QWidget *parent = nullptr);
    ~et_history_window();

    void showHistory() const;

    void setHistory(const history<Matrix<Rational<int64_t>>>& h) {
        e_history = h;
    }

private:
    Ui::et_history_window *ui;
    history<Matrix<Rational<int64_t>>> e_history;
};

#endif // ET_HISTORY_WINDOW_H
