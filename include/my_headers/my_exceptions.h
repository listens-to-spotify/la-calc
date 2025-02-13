#ifndef MY_EXCEPTIONS_H
#define MY_EXCEPTIONS_H

#include <exception>

class EmptyMatrixException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "EmptyMatrixException";
    }
};

class NotSquareMatrixException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "NotSquareMatrixException";
    }
};

class InvalidMatrixSizesException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "NotSquareMatrixException";
    }
};

class InvalidArgumentsException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "InvalidArgumentsException";
    }
};

class DifferentRowLengthException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "DifferentRowLengthException";
    }
};

class ZeroDivisionException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "ZeroDivisionException";
    }
};


#endif // MY_EXCEPTIONS_H
