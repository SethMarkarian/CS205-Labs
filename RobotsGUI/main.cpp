#include "robotsgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RobotsGUI w;
    w.show();

    return a.exec();
}
