#include "functionwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    functionWindow w;
    w.show();
    return a.exec();
}
