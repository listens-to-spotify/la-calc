#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>
#include <iostream>
#include <vector>
#include <tuple>

#include <rational.h>
#include <my_exceptions.h>
#include <my_functions.h>
#include <e_history.h>


template<typename T>
class Identity;


template<typename T = Rational<int64_t>>
class Matrix {
private:
    size_t _m; // rows
    size_t _n; // columns
    std::vector<std::vector<T>> _matrix;
    mutable bool __det_calculated = false;
    mutable T __det_value = 0;
    mutable bool __rank_calculated = false;
    mutable size_t __rank_value = 0;

    void __e1_row(const size_t i_index, const size_t j_index, const T lambda) {
        for (size_t j = 0; j < _n; ++j) {
            (*this)(i_index, j) += lambda * (*this)(j_index, j);
        }
    }

    void __e2_row(const size_t i_index, const size_t j_index) {
        for (size_t j = 0; j < _n; ++j) {
            std::swap((*this)(i_index, j), (*this)(j_index, j));
        }
    }

    void __e3_row(const size_t i_index, const T lambda) {
        if (lambda == 0) {
            throw InvalidArgumentsException();
        }
        for (size_t j = 0; j < _n; ++j) {
            (*this)(i_index, j) *= lambda;
        }
    }

    void __e1_col(const size_t i_index, const size_t j_index, const T lambda) {
        for (size_t i = 0; i < _m; ++i) {
            (*this)(i, i_index) += lambda * (*this)(i, j_index);
        }
    }

    void __e2_col(const size_t i_index, const size_t j_index) {
        for (size_t i = 0; i < _m; ++i) {
            std::swap((*this)(i, i_index), (*this)(i, j_index));
        }
    }

    void __e3_col(const size_t i_index, const T lambda) {
        if (lambda == 0) {
            throw InvalidArgumentsException();
        }
        for (size_t i = 0; i < _m; ++i) {
            (*this)(i, i_index) *= lambda;
        }
    }

    void __toREF(int64_t &swaps) {
        size_t pivot_row = 0;
        size_t pivot_col = 0;
        while (pivot_row < _m && pivot_col < _n) {
            size_t pivot_candidate = pivot_row;
            while (pivot_candidate < _m && (*this)(pivot_candidate, pivot_col) == 0)
                pivot_candidate++;

            if (pivot_candidate == _m) {
                pivot_col++;
                continue;
            }

            if (pivot_candidate != pivot_row) {
                ++swaps;
                __e2_row(pivot_row, pivot_candidate);
            }

            for (size_t i = pivot_row + 1; i < _m; i++) {
                if ((*this)(i, pivot_col) != 0) {
                    T factor = (*this)(i, pivot_col) / (*this)(pivot_row, pivot_col);
                    __e1_row(i, pivot_row, -factor);
                }
            }
            pivot_row++;
            pivot_col++;
        }
    }

    void __clear_flags() {
        __det_calculated = false;
        __rank_calculated = false;
    }

public:
    /****************************************************/
    /*               DEFAULT CONSTRUCTORS               */
    /****************************************************/

    Matrix()
        : _m(0), _n(0), _matrix(), __det_calculated(false), __det_value(0),
        __rank_calculated(false), __rank_value(0) {}

    Matrix(const size_t n) { // square matrix contructor
        _m = n;
        _n = n;
        _matrix.resize(_m, std::vector<T>(_n, 0));
    }

    Matrix(const size_t m, const size_t n) { // rect matrix contructor
        _m = m;
        _n = n;
        _matrix.resize(_m, std::vector<T>(_n, 0));
    }

    Matrix(const std::vector<std::vector<T>> &matrix) {
        _m = matrix.size();
        if (_m == 0) {
            throw EmptyMatrixException();
        }
        _n = matrix[0].size();
        if (_n == 0) {
            throw EmptyMatrixException();
        }

        for (const auto &row : matrix) {
            if (row.size() != _n) {
                throw DifferentSizesException();
            }
        }

        _matrix = matrix;
    }

    /****************************************************/
    /*                RULE OF FIVE                      */
    /****************************************************/


    Matrix(const Matrix& other) { // copy constructor
        _m = other._m;
        _n = other._n;
        _matrix = other._matrix;
    }

    Matrix& operator=(const Matrix& other) { // copy assignment
        if (this != &other) {
            _m = other._m;
            _n = other._n;
            _matrix = other._matrix;
        }
        return *this;
    }

    Matrix(Matrix&& other) noexcept // move constructor
        : _m(other._m)
        , _n(other._n)
        , _matrix(std::move(other._matrix)) {}

    Matrix& operator=(Matrix&& other) noexcept { // move assignment
        std::swap(_m, other._m);
        std::swap(_n, other._n);
        std::swap(_matrix, other._matrix);
        return *this;
    }

    ~Matrix() = default; // desctructor

    /****************************************************/
    /*                  PUBLIC METHODS                  */
    /****************************************************/

    size_t rows() const {
        return _m;
    }
    size_t cols() const {
        return _n;
    }

    std::tuple<size_t, size_t> size() const {
        return std::tuple(_m, _n);
    }

    bool isEmpty() const {
        return (_m == 0 && _n == 0);
    }

    bool isDiag() const {
        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < _n; ++j) {
                if (i != j && (*this)(i, j) != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isIdentity() const {
        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < _n; ++j) {
                if (i != j && (*this)(i, j) != 0) {
                    return false;
                }
                if (i == j && (*this)(i, j) != 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isSymmetric() const {
        if (!this->isSquare()) {
            return false;
        }

        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if ((*this)(i, j) != (*this)(j, i)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isZero() const {
        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < _n; ++j) {
                if ((*this)(i, j) != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isSquare() const {
        return (_m == _n);
    }

    bool isInvertible() const {
        if (__det_calculated) {
            return (__det_value != 0);
        }
        return (this->det() != 0);
    }

    bool isSameSize(const Matrix& rhs) const {
        return (_m == rhs._m && _n == rhs._n);
    }

    bool isMultiplies(const Matrix& rhs) const {
        return (_n == rhs._m);
    }

    Matrix getRowSlice(const size_t begin_index, const size_t end_index) const {
        if (end_index <= begin_index) {
            throw InvalidArgumentsException();
        }
        Matrix temp(end_index - begin_index, _n);
        for (size_t i = 0; i < end_index - begin_index; ++i) {
            for (size_t j = 0; j < _n; ++j) {
                temp(i, j) = (*this)(i + begin_index, j);
            }
        }
        return temp;
    }

    Matrix getColSlice(const size_t begin_index, const size_t end_index) const {
        if (end_index <= begin_index) {
            throw InvalidArgumentsException();
        }
        Matrix temp(_m, end_index - begin_index);
        for (size_t i = 0; i < +_m; ++i) {
            for (size_t j = 0; j < end_index - begin_index; ++j) {
                temp(i, j) = (*this)(i, j + begin_index);
            }
        }
        return temp;
    }

    Matrix getUpperRows(const size_t count) const {
        return this->getRowSlice(0, count);
    }

    Matrix getBottomRows(const size_t count) const {
        return this->getRowSlice(_m - count, _m);
    }

    Matrix getLeftCols(const size_t count) const {
        return this->getColSlice(0, count);
    }

    Matrix getRightCols(const size_t count) const {
        return this->getColSlice(_n - count, _n);
    }

    Matrix transpose() const {
        Matrix temp(_n, _m);
        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < _n; ++j) {
                temp(j, i) = (*this)(i, j);
            }
        }
        return temp;
    }

    T trace() const {
        T result = 0;
        for (size_t i = 0; (i < _n && i < _m); ++i) {
            result += (*this)(i, i);
        }
        return result;
    }

    Matrix inverse() const {
        if (!this->isSquare()) {
            throw NotSquareMatrixException();
        }

        if (!__det_calculated) {
            this->det();
        }

        if (__det_value.num()) {
            Matrix M = *this;
            Identity<T> I(_n);
            M.toRREF(I);
            return I;
        } else {
            throw NotInvertibleMatrixException();
        }
    }

    Matrix pow(unsigned power) const {
        if (!this->isSquare()) {
            throw NotSquareMatrixException();
        }

        if (power == 0) {
            return Identity<Rational<int64_t>>(_n);
        }

        if (power == 1) {
            return *this;
        }

        auto result = *this;
        power -= 1;

        while (power-- > 0) {
            result *= *this;
        }
        return result;
    }

    size_t rank() const {
        if (__rank_calculated) {
            return __rank_value;
        }

        Matrix temp = *this;
        temp.toREF();
        size_t null_rows = 0;
        for (int64_t i = temp.rows() - 1; i >= 0; --i) {
            bool isNullRow = true;
            for (size_t j = 0; j < temp.cols(); ++j) {
                if (temp(i, j) != 0) {
                    isNullRow = false;
                }
            }
            if (isNullRow) {
                null_rows += 1;
            } else {
                break;
            }
        }
        __rank_value = _m - null_rows;
        __rank_calculated = true;
        return _m - null_rows;
    }

    T det() const {
        if (!this->isSquare()) {
            throw NotSquareMatrixException();
        }

        if (__det_calculated) {
            return __det_value;
        }

        Matrix temp = *this;
        int64_t swaps = 0;
        temp.__toREF(swaps);
        T result = ((swaps % 2) ? -1 : 1);
        for (size_t i = 0; i < temp.cols(); ++i) {
            result *= temp(i, i);
        }
        __det_value = result;
        __det_calculated = true;
        return result;
    }

    Matrix joinRight(const Matrix& rhs) const {
        if (_m != rhs.rows()) {
            throw DifferentSizesException();
        }
        Matrix temp(_m, _n + rhs.cols());
        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < temp.cols(); ++j) {
                if (j < _n) {
                    temp(i, j) = (*this)(i, j);
                } else {
                    temp(i, j) = rhs(i, j - _n);
                }
            }
        }
        return temp;
    }

    /****************************************************/
    /*                ACCESS OPERATORS                  */
    /****************************************************/

    T& operator()(size_t i_index, size_t j_index) {
        if (i_index >= _m || j_index >= _n) {
            throw InvalidArgumentsException();
        }
        return _matrix[i_index][j_index];
    }

    const T& operator()(size_t i_index, size_t j_index) const {
        if (i_index >= _m || j_index >= _n) {
            throw InvalidArgumentsException();
        }
        return _matrix[i_index][j_index];
    }

    /****************************************************/
    /*               ARITHMETIC OPERATORS               */
    /****************************************************/


    Matrix operator+(const Matrix& rhs) const {
        if (!this->isSameSize(rhs)) {
            throw DifferentSizesException();
        }

        Matrix temp(_m, _n);
        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < _n; ++j) {
                temp(i, j) = (*this)(i, j) + rhs(i, j);
            }
        }

        return temp;
    }

    Matrix operator-() const {

        Matrix temp(_m, _n);
        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < _n; ++j) {
                temp(i, j) = -(*this)(i, j);
            }
        }
        return temp;
    }

    Matrix operator-(const Matrix& rhs) const {
        if (!this->isSameSize(rhs)) {
            throw DifferentSizesException();
        }

        Matrix temp(_m, _n);
        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < _n; ++j) {
                temp(i, j) = (*this)(i, j) - rhs(i, j);
            }
        }

        return temp;
    }

    Matrix operator*(const Matrix& rhs) const {
        if (!this->isMultiplies(rhs)) {
            throw NotMultipliableException();
        }

        Matrix temp(_m, rhs._n);
        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < rhs._n; ++j) {
                temp(i, j) = 0;
                for (size_t k = 0; k < _n; ++k) {
                    temp(i, j) += (*this)(i, k) * rhs(k, j);
                }
            }
        }

        return temp;
    }

    template <typename R>
    friend Matrix operator*(const R& k, const Matrix& rhs) {
        Matrix temp(rhs._m, rhs._n);
        for (size_t i = 0; i < rhs._m; ++i) {
            for (size_t j = 0; j < rhs._n; ++j) {
                temp(i, j) *= k;
            }
        }

        return temp;
     }

    template <typename R>
    friend Matrix operator*(const Matrix& lhs, const R& k) {
        Matrix temp(lhs._m, lhs._n);
        for (size_t i = 0; i < lhs._m; ++i) {
            for (size_t j = 0; j < lhs._n; ++j) {
                temp(i, j) *= k;
            }
        }

        return temp;
    }

    template <typename R>
    friend Matrix operator/(const Matrix& lhs, const R& k) {
        Matrix temp(lhs._m, lhs._n);
        for (size_t i = 0; i < lhs._m; ++i) {
            for (size_t j = 0; j < lhs._n; ++j) {
                temp(i, j) /= k;
            }
        }

        return temp;
    }

    /****************************************************/
    /*          ARITHMETIC ASSIGNMENT OPERATORS         */
    /****************************************************/


    Matrix& operator+=(const Matrix& rhs) {
        this->__clear_flags();
        return *this = *this + rhs;
    }

    Matrix& operator-=(const Matrix& rhs) {
        this->__clear_flags();
        return *this = *this - rhs;
    }

    Matrix& operator*=(const Matrix& rhs) {
        this->__clear_flags();
        return *this = *this * rhs;
    }

    /****************************************************/
    /*                IOSTREAM OPERATORS                */
    /****************************************************/

    friend std::ostream& operator<<(std::ostream& os, const Matrix& rhs) {
        for (size_t i = 0; i < rhs._m; ++i) {
            for (size_t j = 0; j < rhs._n; ++j) {
                os << rhs(i, j);
                (j == rhs._n - 1) ? os << '\n' : os << ' ';
            }
        }
        return os;
    }

    /****************************************************/
    /*                BOOL COMPARISONS                  */
    /****************************************************/

    bool operator==(const Matrix& rhs) const {
        if (!this->isSameSize(rhs)) {
            throw DifferentSizesException();
        }

        for (size_t i = 0; i < _m; ++i) {
            for (size_t j = 0; j < _n; ++j) {
                if ((*this)(i, j) != rhs(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool operator!=(const Matrix& rhs) const {
        return !(*this == rhs);
    }

    /****************************************************/
    /*                   ALGORITHMS                     */
    /****************************************************/

    void toREF() {
        this->__clear_flags();
        size_t pivot_row = 0;
        size_t pivot_col = 0;
        while (pivot_row < _m && pivot_col < _n) {
            size_t pivot_candidate = pivot_row;
            while (pivot_candidate < _m && (*this)(pivot_candidate, pivot_col) == 0)
                pivot_candidate++;

            if (pivot_candidate == _m) {
                pivot_col++;
                continue;
            }

            if (pivot_candidate != pivot_row) {
                __e2_row(pivot_row, pivot_candidate);
            }

            for (size_t i = pivot_row + 1; i < _m; i++) {
                if ((*this)(i, pivot_col) != 0) {
                    T factor = (*this)(i, pivot_col) / (*this)(pivot_row, pivot_col);
                    __e1_row(i, pivot_row, -factor);
                }
            }
            pivot_row++;
            pivot_col++;
        }
    }

    void toRREF() {
        this->__clear_flags();
        this->toREF();

        for (int64_t i = _m - 1; i >= 0; i--) {
            size_t pivot_col = 0;
            bool pivot_found = false;
            for (size_t j = 0; j < _n; j++) {
                if ((*this)(i, j) != 0) {
                    pivot_col = j;
                    pivot_found = true;
                    break;
                }
            }
            if (!pivot_found)
                continue;

            T pivot_val = (*this)(i, pivot_col);
            __e3_row(i, T(1) / pivot_val);

            for (int64_t k = i - 1; k >= 0; k--) {
                T factor = (*this)(k, pivot_col);
                if (factor != 0) {
                    __e1_row(k, i, -factor);
                }
            }
        }
    }

    void toREF(Matrix& b){
        this->__clear_flags();
        size_t pivot_row = 0;
        size_t pivot_col = 0;
        while (pivot_row < _m && pivot_col < _n) {
            size_t pivot_candidate = pivot_row;
            while (pivot_candidate < _m && (*this)(pivot_candidate, pivot_col) == 0)
                pivot_candidate++;

            if (pivot_candidate == _m) {
                pivot_col++;
                continue;
            }

            if (pivot_candidate != pivot_row) {
                __e2_row(pivot_row, pivot_candidate);
                b.__e2_row(pivot_row, pivot_candidate);
            }

            for (size_t i = pivot_row + 1; i < _m; i++) {
                if ((*this)(i, pivot_col) != 0) {
                    T factor = (*this)(i, pivot_col) / (*this)(pivot_row, pivot_col);
                    __e1_row(i, pivot_row, -factor);
                    b.__e1_row(i, pivot_row, -factor);
                }
            }
            pivot_row++;
            pivot_col++;
        }
    }

    void toRREF(Matrix& b){
        this->__clear_flags();
        this->toREF(b);

        for (int64_t i = _m - 1; i >= 0; i--) {
            size_t pivot_col = 0;
            bool pivot_found = false;
            for (size_t j = 0; j < _n; j++) {
                if ((*this)(i, j) != 0) {
                    pivot_col = j;
                    pivot_found = true;
                    break;
                }
            }
            if (!pivot_found)
                continue;

            T pivot_val = (*this)(i, pivot_col);
            __e3_row(i, T(1) / pivot_val);
            b.__e3_row(i, T(1) / pivot_val);

            for (int64_t k = i - 1; k >= 0; k--) {
                T factor = (*this)(k, pivot_col);
                if (factor != 0) {
                    __e1_row(k, i, -factor);
                    b.__e1_row(k, i, -factor);
                }
            }
        }
    }

    Matrix symmetricGauss(Matrix& rhs) {
        this->__clear_flags();
        if (!this->isSquare()) {
            throw NotSquareMatrixException();
        }

        if (!this->isSymmetric()) {
            throw NotSymmetricMatrixException();
        }

        if (!this->isSameSize(rhs)){
            throw DifferentSizesException();
        }

        size_t n = _m;

        for (size_t i = 0; i < n; ++i) {
            if ((*this)(i, i) == 0) {
                size_t pivot_j = n;
                for (size_t j = i + 1; j < n; ++j) {
                    if ((*this)(i, j) != 0) { // found not null row
                        pivot_j = j;
                        break;
                    }
                }
                if (pivot_j < n) { // if found not null row -> add it to the i-th row, so pivot elem is not null
                    __e1_row(i, pivot_j, T(1));
                    __e1_col(i, pivot_j, T(1));

                    rhs.__e1_row(i, pivot_j, T(1));

                }
            }

            if ((*this)(i, i) == 0) // this called when now pivot elem found -> whole col is null -> continue
                continue;

            for (size_t j = i + 1; j < n; ++j) {
                T factor = (*this)(j, i) / (*this)(i, i);
                if (factor != 0) {
                    __e1_row(j, i, -factor);
                    rhs.__e1_row(j, i, -factor);
                    __e1_col(j, i, -factor);
                }
            }
        }
        return rhs;
    }

    Matrix symmetricGauss(Matrix& rhs, history<Matrix<T>>& h) {
        this->__clear_flags();
        if (!this->isSquare()) {
            throw NotSquareMatrixException();
        }

        if (!this->isSymmetric()) {
            throw NotSymmetricMatrixException();
        }

        if (!this->isSameSize(rhs)){
            throw DifferentSizesException();
        }

        size_t n = _m;

        for (size_t i = 0; i < n; ++i) {
            if ((*this)(i, i) == 0) {
                size_t pivot_j = n;
                for (size_t j = i + 1; j < n; ++j) {
                    if ((*this)(i, j) != 0) { // found not null row
                        pivot_j = j;
                        break;
                    }
                }
                if (pivot_j < n) { // if found not null row -> add it to the i-th row, so pivot elem is not null
                    T factor = T(1);
                    __e1_row(i, pivot_j, factor);
                    rhs.__e1_row(i, pivot_j, factor);
                    std::pair<Matrix<T>, Matrix<T>> pair(*this, rhs);
                    h.emplace_back(et("row", i, pivot_j, factor), pair);

                    __e1_col(i, pivot_j, factor);
                    pair.first = *this; pair.second = rhs;
                    h.emplace_back(et("col", i, pivot_j, factor), pair);
                }
            }

            if ((*this)(i, i) == 0) // this called when now pivot elem found -> whole col is null -> continue
                continue;

            for (size_t j = i + 1; j < n; ++j) {
                T factor = (*this)(j, i) / (*this)(i, i);
                if (factor != 0) {
                    __e1_row(j, i, -factor);
                    rhs.__e1_row(j, i, -factor);
                    std::pair<Matrix<T>, Matrix<T>> pair(*this, rhs);
                    h.emplace_back(et("row", j, i, -factor), pair);

                    __e1_col(j, i, -factor);
                    pair.first = *this; pair.second =rhs;
                    h.emplace_back(et("col", j, i, -factor), pair);
                }
            }
        }
        return rhs;
    }
};


template<typename T = Rational<int64_t>>
class Identity : public Matrix<T> {
public:
    Identity(const size_t n) : Matrix<T>(n) {
        for (size_t i = 0; i < this->cols(); ++i) {
            (*this)(i, i) = 1;
        }
    }
};

#endif // MATRIX_H
