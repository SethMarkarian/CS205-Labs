#include "wormgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WormGUI w;
    w.show();

    return a.exec();
}
