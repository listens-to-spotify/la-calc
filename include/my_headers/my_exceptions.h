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

class NotDiagnalMatrixExcception : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "NotDiagnalMatrixExcception";
    }
};

class NotInvertibleMatrixException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "NotInvertibleMatrixException";
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

class NotMultipliableException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "NotMultipliableException";
    }
};

class DifferentSizesException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "DifferentSizesException";
    }
};

class ZeroDivisionException : public std::exception
{   public:
    virtual const char* what() const throw() {
        return "ZeroDivisionException";
    }
};


#endif // MY_EXCEPTIONS_H
