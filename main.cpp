#include "zsqlmanagerwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZSQLManagerWindow w;
    w.show();
    return a.exec();
}
