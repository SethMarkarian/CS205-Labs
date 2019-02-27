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

    void on_quit_button_clicked();

    void on_N_button_clicked();

    void on_S_button_clicked();

    void on_W_button_clicked();

    void on_E_button_clicked();

    void on_T_button_clicked();

private:

    Robots* r;

    void draw_board();

    Ui::RobotsGUI *ui;
};

#endif // ROBOTSGUI_H
