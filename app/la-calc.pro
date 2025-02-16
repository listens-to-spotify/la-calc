QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# QMAKE_CXXFLAGS += -std=c++17
# QMAKE_CC = gcc-10
# QMAKE_CXX = g++-10
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow/mainwindow.cpp \
    sle-window/sle.cpp \
    gauss-window/gauss.cpp \
    sym-gauss-window/symmetric_gauss.cpp

HEADERS += \
    ../include/my_headers/my_functions.h \
    ../include/my_headers/my_exceptions.h \
    ../include/my_headers/rational.h \
    ../include/my_headers/matrix.h \
    sle-window/sle.h \
    gauss-window/gauss.h \
    sym-gauss-window/symmetric_gauss.h

FORMS += \
    mainwindow/mainwindow.ui \
    sle-window/sle.ui \
    gauss-window/gauss.ui \
    sym-gauss-window/symmetric_gauss.ui

INCLUDEPATH += ../include/my_headers

# Default rules for deployment.
# qnx: target.path = /tmp/$${TARGET}/bin
# else: unix:!android: target.path = /opt/$${TARGET}/bin
# !isEmpty(target.path): INSTALLS += target
