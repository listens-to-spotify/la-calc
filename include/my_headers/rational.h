#ifndef RATIONAL_H
#define RATIONAL_H

#include <cstdint>
#include <iostream>
#include <my_exceptions.h>
#include <my_functions.h>

template <typename T = int32_t>
class Rational {
private:
    T _num;
    T _denom;

public:

    /****************************************************/
    /*               DEFAULT CONSTRUCTORS               */
    /****************************************************/

    Rational(const T n) {
        _num = n;
        _denom = 1;
    }

    Rational(const T p, const T q) {
        if (q == 0) throw ZeroDivisionException();

        if (q < 0) {
            _num = -p;
            _denom = -q;
        } else {
            _num = p;
            _denom = q;
        }
        this->Normalize();
    }

    /****************************************************/
    /*                RULE OF FIVE                      */
    /****************************************************/


    Rational(const Rational& other) { // copy constructor
        _num = other._num;
        _denom = other._denom;
    }

    Rational& operator=(const Rational& other) { // copy assignment
        if (this != &other) {
            _num = other._num;
            _denom = other._denom;
        }
        return *this;
    }

    Rational(Rational&& other) noexcept // move constructor
        : _num(std::move(other._num)), _denom(std::move(other._denom)) {}

    Rational& operator=(Rational&& other) noexcept { // move assignment
        std::swap(_num, other._num);
        std::swap(_denom, other._denom);
        return *this;
    }

    ~Rational() = default; // desctructor

    /****************************************************/
    /*                  PUBLIC METHODS                  */
    /****************************************************/

    T num() const {
        return _num;
    }
    T denom() const {
        return _denom;
    }

    void Normalize() {
        T g = gcd(_denom, _num);
        _denom /= g;
        _num /= g;
    }

    Rational inverse() const {
        return Rational(_denom, _num);
    }

    Rational pow(int power) const {
        if (power == 0) return Rational(1);
        Rational base = (power < 0) ? this->inverse() : *this;
        power = std::abs(power);
        Rational result(1);
        while (power) {
            if (power % 2) result *= base;
            base *= base;
            power /= 2;
        }
        return result;
    }

    double toDouble() const {
        return static_cast<double>(_num) / _denom;
    }

    Rational toAbs() const {
        return Rational(std::abs(_num), _denom);
    }

    bool isInteger() const {
        return (_denom == 1);
    }

    /****************************************************/
    /*               ARITHMETIC OPERATORS               */
    /****************************************************/


    Rational operator+(const Rational& rhs) const {
        Rational temp(_num * rhs._denom + _denom * rhs._num, _denom * rhs._denom);
        temp.Normalize();
        return temp;
    }

    Rational operator-() const {
        return Rational(-_num, _denom);
    }

    Rational operator-(const Rational& rhs) const {
        return *this + (-rhs);
    }

    Rational operator*(const Rational& rhs) const {
        Rational temp(_num * rhs._num, _denom * rhs._denom);
        temp.Normalize();
        return temp;
    }

    Rational operator/(const Rational& rhs) const {
        Rational temp(_num * rhs._denom, _denom * rhs._num);
        temp.Normalize();
        return temp;
    }

    /****************************************************/
    /*          ARITHMETIC ASSIGNMENT OPERATORS         */
    /****************************************************/


    Rational& operator+=(const Rational& rhs) {
        return *this = *this + rhs;
    }


    Rational& operator-=(const Rational& rhs) {
        return *this = *this - rhs;
    }

    Rational& operator*=(const Rational& rhs) {
        return *this = *this * rhs;
    }

    Rational& operator/=(const Rational& rhs) {
        return *this = *this / rhs;
    }

    /****************************************************/
    /*                IOSTREAM OPERATORS                */
    /****************************************************/

    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r._num << "/" << r._denom;
        return os;
    }

    /****************************************************/
    /*                BOOL COMPARISONS                  */
    /****************************************************/

    bool operator==(const Rational& rhs) const {
        return (_num * rhs._denom == _denom * rhs._num);
    }

    bool operator!=(const Rational& rhs) const {
        return !(*this == rhs);
    }

    bool operator>(const Rational& rhs) const {
        return (_num * rhs._denom > _denom * rhs._num);
    }

    bool operator<(const Rational& rhs) const {
        return (_num * rhs._denom < _denom * rhs._num);
    }

    bool operator>=(const Rational& rhs) const {
        return (_num * rhs._denom >= _denom * rhs._num);
    }

    bool operator<=(const Rational& rhs) const {
        return (_num * rhs._denom <= _denom * rhs._num);
    }
};


#endif // RATIONAL_H
