#include "tinygame.h"
#include "ui_tinygame.h"

TinyGame::TinyGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TinyGame)
{
    ui->setupUi(this);

    // initialize the gameboard
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            board[row][col] = ' ';
        }
    }

    // initialize the hero and place on gameboard
    hero_row = 1;
    hero_col = COLS / 2;

    board[hero_row][hero_col] = '*';

    draw_board();
}

TinyGame::~TinyGame()
{
    delete ui;
}

void TinyGame::on_west_button_clicked()
{
    char temp = board[hero_row][hero_col];

    if (hero_col > 0) {

        board[hero_row][hero_col] = board[hero_row][hero_col - 1];

        board[hero_row][hero_col - 1] = temp;

        hero_col--;

        draw_board();
    }
}

void TinyGame::on_north_button_clicked()
{
    if (hero_row > 0) {

        char temp = board[hero_row][hero_col];

        board[hero_row][hero_col] = board[hero_row - 1][hero_col];

        board[hero_row - 1][hero_col] = temp;

        hero_row--;

        draw_board();
    }
}

void TinyGame::on_south_button_clicked()
{
    if (hero_row < (ROWS - 1)) {

        char temp = board[hero_row][hero_col];

        board[hero_row][hero_col] = board[hero_row + 1][hero_col];

        board[hero_row + 1][hero_col] = temp;

        hero_row++;

        draw_board();
    }
}

void TinyGame::on_east_button_clicked()
{
    if (hero_col < (COLS - 1)) {

        char temp = board[hero_row][hero_col];

        board[hero_row][hero_col] = board[hero_row][hero_col + 1];

        board[hero_row][hero_col + 1] = temp;

        hero_col++;

        draw_board();
    }
}

void TinyGame::on_quit_button_clicked()
{
    //  the window by calling close slot
    close();
}

void TinyGame::draw_board() {

    QString temp_board = "";

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            temp_board += board[row][col];
        }
        temp_board += '\n';
    }

    //    std::cerr << temp_board.toStdString() << "\n";

    ui->board_display->clear();
    ui->board_display->setText(temp_board);
}
