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
    /**
     * @brief on_quit_button_clicked quits the game when the button is pressed
     */
    void on_quit_button_clicked();

    /**
     * @brief on_down_button_clicked moves the worm down when the button is pressed
     */
    void on_down_button_clicked();

    /**
     * @brief on_right_button_clicked moves the worm right when the button is pressed
     */
    void on_right_button_clicked();

    /**
     * @brief on_up_button_clicked moves the worm up when the button is pressed
     */
    void on_up_button_clicked();

    /**
     * @brief on_left_button_clicked moves the worm left when the button is pressed
     */
    void on_left_button_clicked();

private:
    int ro; // rows of the game
    int co; // columns of the game
    Worm * wurm; // worm engine being played
    void draw_board(); // draws the board of the GUI
    void lost(); // determines if the player has lost, therefore if the game should quit
    Ui::WormGUI *ui;
};

#endif // WORMGUI_H
