#include "wormgui.h"
#include "ui_wormgui.h"

WormGUI::WormGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WormGUI)
{
    ui->setupUi(this);
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
    close();
}

void WormGUI::draw_board()
{
    QString temp_board = "";

    for(int row = 0; row < ro; row++) {
        for(int col = 0; col < co; col++) {
            temp_board += wurm->get(row, col);
        }
        temp_board += '\n';
    }
    ui->board_display->clear();
    ui->board_display->setText(temp_board);
}

void WormGUI::on_down_button_clicked()
{
    wurm -> down();
    draw_board();
}

void WormGUI::on_right_button_clicked()
{
    wurm -> right();
    draw_board();
}

void WormGUI::on_up_button_clicked()
{
    wurm -> up();
    draw_board();
}

void WormGUI::on_left_button_clicked()
{
    wurm -> left();
    draw_board();
}
