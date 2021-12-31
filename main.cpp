#include <QtWidgets/QApplication>
#include "starter.h"

int main(int argc, char *argv[])
{

    //解决Qt界面设计器中的界面预览与程序运行时界面不一样的问题
    if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    /*Log w;*/
    Starter w;
    w.showLog();
    return a.exec();
}
