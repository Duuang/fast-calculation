#include "QtGuiApplication.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    //QTextCodec::codecForName("GB2312");

    QApplication a(argc, argv);
    QtGuiApplication w;
    w.show();
    
    return a.exec();
}
