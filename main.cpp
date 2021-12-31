#include <QtWidgets/QApplication>
#include "starter.h"

int main(int argc, char *argv[])
{

    //���Qt����������еĽ���Ԥ�����������ʱ���治һ��������
    if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    /*Log w;*/
    Starter w;
    w.showLog();
    return a.exec();
}
