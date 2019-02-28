#ifndef WORMGUI_H
#define WORMGUI_H

#include <QWidget>
#include <QString>
#include <iostream>

#include "../Engines/engine.h"
#include "../Engines/worm.h"

namespace Ui {
class WormGUI;
}

class WormGUI : public QWidget
{
    Q_OBJECT

public:
    explicit WormGUI(QWidget *parent = nullptr);
    ~WormGUI();

private slots:
    void on_quit_button_clicked();

    void on_down_button_clicked();

    void on_right_button_clicked();

    void on_up_button_clicked();

    void on_left_button_clicked();

private:
    int ro;
    int co;
    Worm * wurm;
    void draw_board();
    Ui::WormGUI *ui;
};

#endif // WORMGUI_H
