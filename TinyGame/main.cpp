#include "tinygame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TinyGame w;
    w.show();

    return a.exec();
}
