QT += core gui widgets

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

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
    mainwindow/mainwindow.h \
    sle-window/sle.h \
    gauss-window/gauss.h \
    sym-gauss-window/symmetric_gauss.h

FORMS += \
    mainwindow/mainwindow.ui \
    sle-window/sle.ui \
    gauss-window/gauss.ui \
    sym-gauss-window/symmetric_gauss.ui

INCLUDEPATH += ../include/my_headers

# Настройки RPATH
QMAKE_LFLAGS += -Wl,-rpath,@executable_path/../Frameworks
QMAKE_LFLAGS += -Wl,-rpath,/opt/homebrew/opt/qt@6/lib
