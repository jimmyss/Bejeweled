#include "xxlProject.h"
#include <QtWidgets/QApplication>

#include "DButil.h"

int main(int argc, char *argv[])
{
    //Qt界面设计器中的界面预览与程序运行时界面不一样
    if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    xxlProject w;
    w.show();
    return a.exec();
}
