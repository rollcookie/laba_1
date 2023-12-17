#include "Colors.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Colors w;
    w.show();
    return a.exec();
}
