#ifndef ROBOTSGUI_H
#define ROBOTSGUI_H

#include <QWidget>
#include <QString>
#include <iostream>

#include "../Engines/engine.h"
#include "../Engines/robots.h"

namespace Ui {
class RobotsGUI;
}

class RobotsGUI : public QWidget
{
    Q_OBJECT

public:
    explicit RobotsGUI(QWidget *parent = nullptr);
    ~RobotsGUI();

private slots:
    void on_west_button_clicked();
    void on_north_button_clicked();
    void on_south_button_clicked();
    void on_east_button_clicked();

    void on_quit_button_clicked();

private:

    Robots* r;

    void draw_board();

    Ui::RobotsGUI *ui;
};

#endif // ROBOTSGUI_H
