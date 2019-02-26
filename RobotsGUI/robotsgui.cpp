#include "robotsgui.h"
#include "ui_robotsgui.h"

RobotsGUI::RobotsGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RobotsGUI)
{
    ui->setupUi(this);
    r = new Robots();
    draw_board();
}

RobotsGUI::~RobotsGUI()
{
    delete ui;
}

void RobotsGUI::on_west_button_clicked() {
    r->movePlayerW();
    draw_board();
}

void RobotsGUI::on_north_button_clicked() {
    r->movePlayerN();
    draw_board();
}

void RobotsGUI::on_south_button_clicked() {
    r->movePlayerS();
    draw_board();
}

void RobotsGUI::on_east_button_clicked() {
    r->movePlayerE();
}

void RobotsGUI::on_quit_button_clicked() {
    close();
}

void RobotsGUI::draw_board() {
    QString temp_board = "";

    for(int row = 0; row < r->getRows(); row++) {
        for(int col = 0; col < r->getCols(); col++) {
            temp_board += r->gameboard[row][col];
        }
        temp_board += '\n';
    }


}
