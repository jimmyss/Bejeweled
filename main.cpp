#include "xxlProject.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    xxlProject w;
    w.show();
    return a.exec();
}
