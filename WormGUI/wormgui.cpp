#include "wormgui.h"
#include "ui_wormgui.h"

WormGUI::WormGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WormGUI)
{
    ui->setupUi(this);
}

WormGUI::~WormGUI()
{
    delete ui;
    delete wurm;
}


void WormGUI::on_up_button_clicked()
{
    wurm -> up();
}

void WormGUI::on_down_button_clicked()
{
    wurm -> down();
}

void WormGUI::on_left_button_clicked()
{
    wurm -> left();
}

void WormGUI::on_right_button_clicked()
{
    wurm -> right();
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
            temp_board += wurm -> get(ro, co);
        }
        temp_board += '\n';
    }

    ui->board_display->clear();
    ui->board_display->setText(temp_board);
}
