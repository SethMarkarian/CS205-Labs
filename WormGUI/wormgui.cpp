#include "wormgui.h"
#include "ui_wormgui.h"

WormGUI::WormGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WormGUI)
{
    ui->setupUi(this);
    // assign instance variables
    ro = 15;
    co = 30;
    wurm = new Worm(ro, co);
    draw_board();
}

WormGUI::~WormGUI()
{
    delete ui;
    delete wurm;
}

void WormGUI::on_quit_button_clicked()
{
    // closes the game
    close();
}

void WormGUI::draw_board()
{
    // creates a long string of the gameboard
    QString temp_board = "";

    for(int row = 0; row < ro; row++) {
        for(int col = 0; col < co; col++) {
            temp_board += wurm->get(row, col);
        }
        temp_board += '\n';
    }
    // convert the score to a string
    std::string sc;
    sc += std::to_string(wurm->score);
    QString qscore = QString::fromStdString(sc);
    // add the score below the game board
    temp_board += sc.c_str();
    temp_board += '\n';
    ui->board_display->clear();
    ui->board_display->setText(temp_board);
}

void WormGUI::on_down_button_clicked()
{
    wurm -> down(); // move worm down
    lost(); // determine if lost
    draw_board(); // draw the board
}

void WormGUI::on_right_button_clicked()
{
    wurm -> right(); // move right down
    lost(); // deterimine if lost
    draw_board(); // draw the board
}

void WormGUI::on_up_button_clicked()
{
    wurm -> up(); // move worm up
    lost();  // determine if lost
    draw_board(); // draw the board
}

void WormGUI::on_left_button_clicked()
{
    wurm -> left(); // move worm left
    lost(); // determine if lost
    draw_board(); // draw the board
}

void WormGUI::lost()
{
    if(wurm->lost_yet) // if the player lost...
    {
        // close the game
        close();
    }
}
