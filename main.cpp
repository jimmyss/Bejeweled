#include "Log.h"
#include <QtWidgets/QApplication>

#include "DButil.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Log w;
    w.show();
    return a.exec();
}
