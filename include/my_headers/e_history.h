#ifndef E_HISTORY_H
#define E_HISTORY_H

#include <string>
#include <rational.h>
#include <iostream>
#include <vector>

struct et {
    int type;
    std::string target;
    size_t i;
    size_t j;
    Rational<int64_t> factor;

    et(std::string target, const size_t i, const size_t j, const Rational<int64_t>& factor) :
        type(1),
        target(target),
        i(i),
        j(j),
        factor(factor) {}

    et(std::string target, const size_t i, const size_t j) :
        type(2),
        target(target),
        i(i),
        j(j),
        factor(0) {}

    et(std::string target, const size_t i, const Rational<int64_t>& factor) :
        type(3),
        target(target),
        i(i),
        j(0),
        factor(factor) {}

    friend std::ostream& operator<<(std::ostream& os, const et& rhs) {
        if (rhs.type == 1) {
            os << "e1_" << rhs.target << "(" << rhs.i << ", " << rhs.j << ", " << rhs.factor << ')';
            return os;
        }
        if (rhs.type == 2) {
            os << "e2_" << rhs.target << "(" << rhs.i << ", " << rhs.j << ')';
            return os;
        }
        os << "e3_" << rhs.target << "(" << rhs.i << ", " << rhs.factor << ')';
        return os;
    }
};

template <typename T>
struct history {
    std::pair<T, T> start;
    std::vector<std::pair<et, std::pair<T, T>>> h;

    void emplace_back(const et& e, std::pair<T, T> &matrixs) {
        h.emplace_back(e, matrixs);
    }

    void set_start(const std::pair<T, T>& matrix){
        start = matrix;
    }

    void clear() {
        h.clear();
    }
};

#endif // E_HISTORY_H
