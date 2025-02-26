#include <mainwindow/mainwindow.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(w.windowFlags() & ~Qt::WindowMaximizeButtonHint);
    w.setFixedSize(875, 670);
    w.show();
    std::cout << Rational<int64_t>(-1050, 3901) + Rational<int64_t>(-902, 3901) * Rational<int64_t>(-451, 380);
    return a.exec();
}
