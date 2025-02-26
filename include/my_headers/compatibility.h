#ifndef COMPATIBILITY_H
#define COMPATIBILITY_H

#include <QString>
#include <QStringList>
#include <matrix.h>
#include <rational.h>
#include <my_exceptions.h>
#include <e_history.h>

inline Matrix<Rational<int64_t>> fromQStringToMatrix(const QString& input) {
    QStringList input_list = input.split('\n');
    for (auto &s : input_list) {
        s.remove('&');
        s.remove('\\');
        s.remove("frac");
        s.replace("}{", "/");
        s.remove('{');
        s.remove('}');
    }

    std::vector<QStringList> rows;
    for (auto &s : input_list) {
        s = s.simplified();
        if (!s.isEmpty()) {
            rows.push_back(s.split(' '));
        }
    }

    const size_t m = rows.size(); // m -- number of rows
    if (!m) {
        throw EmptyMatrixException();
    }

    const size_t n = rows[0].size(); // n -- number of columns
    if (!n) {
        throw EmptyMatrixException();
    }

    for (const auto& row : rows) {
        if (static_cast<size_t>(row.size()) != n) {
            // if row.size not equals to number of columns -- exception
            throw DifferentSizesException();
        }
    }

    Matrix<Rational<int64_t>> M(m, n);
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            const QString& value = rows[i][j];
            if (value.contains('/')) {
                int64_t p, q;
                const QStringList splitted_value = value.split('/');
                p = splitted_value[0].toInt();
                q = splitted_value[1].toInt();
                if (q) {
                    M(i, j) = Rational(p, q);
                } else {
                    throw ZeroDivisionException();
                }
            } else {
                M(i, j) = Rational(value.toLong());
            }
        }
    }
    return M;
}

inline QString fromRationalToQString(const Rational<int64_t>& x) {
    const int64_t p = x.num();
    const int64_t q = x.denom();
    if (q == 1) {
        return QString::number(p);
    }
    return QString::number(p) + QString("/") + QString::number(q);
}

inline QString fromRationalToQString(Rational<int64_t>&& x) {
    const int64_t p = x.num();
    const int64_t q = x.denom();
    if (q == 1) {
        return QString::number(p);
    }
    return QString::number(p) + QString("/") + QString::number(q);
}

inline QString fromMatrixToQString(const Matrix<Rational<int64_t>> &M) {
    QString result = "";

    for (size_t i = 0; i < M.rows(); ++i) {
        QString row = "";
        for (size_t j = 0; j < M.cols(); ++j) {
            row += fromRationalToQString(Rational(M(i, j)));
            if (j != M.cols() - 1) {
                row += " ";
            } else {
                row += "\n";
            }
        }
        result += row;
    }

    return result;
}

inline QString fromRationalToQStringTeX(Rational<int64_t>&& x) {
    int64_t p = x.num();
    const int64_t q = x.denom();
    if (q == 1) {
        return QString::number(p);
    }
    if (p == 0) {
        return QString("0");
    }
    if (p > 0) {
        return QString("\\frac{%1}{%2}").arg(QString::number(p)).arg(QString::number(q));
    }
    p *= -1;
    return QString("-\\frac{%1}{%2}").arg(QString::number(p)).arg(QString::number(q));
}

inline  QString fromMatrixToQStringTex(const Matrix<Rational<int64_t>> &M){
    QString result = "";

    for (size_t i = 0; i < M.rows(); ++i) {
        QString row = "";
        for (size_t j = 0; j < M.cols(); ++j) {
            row += fromRationalToQStringTeX(Rational(M(i, j)));
            if (j != M.cols() - 1) {
                row += " & ";
            } else {
                row += " \\\\\n";
            }
        }
        result += row;
    }
    return result;
}

inline QString fromHistoryToQString(const history<Matrix<Rational<int64_t>>>& his) {
    QString result = "Start\n";

    result += fromMatrixToQString(
        his.start.first.joinRight(his.start.second)
    ) + "\n";

    for (const auto& [e, m_pair] : his.h){

        if (e.type == 1) {
            result += QString("e1_") + QString::fromStdString(e.target) + "(";
            result += QString(QString::number(e.i)) + ", " + QString::number(e.j) + ", " + fromRationalToQString(e.factor) + ")\n";
            result += fromMatrixToQString(m_pair.first.joinRight(m_pair.second));
        }
        if (e.type == 2) {
            result += QString("e2_") + QString::fromStdString(e.target) + "(";
            result += QString(QString::number(e.i)) + ", " + QString::number(e.j) + ")\n";
            result += fromMatrixToQString(m_pair.first.joinRight(m_pair.second));
        }
        if (e.type == 3) {
            result += QString("e3_") + QString::fromStdString(e.target) + "(";
            result += QString(QString::number(e.i)) + ", " + fromRationalToQString(e.factor) + ")\n";
            result += fromMatrixToQString(m_pair.first.joinRight(m_pair.second));
        }

        result += "\n";
    }
    return result;
}

#endif // COMPATIBILITY_H
