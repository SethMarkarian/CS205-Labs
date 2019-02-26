#ifndef TINYGAME_H
#define TINYGAME_H

#include <QWidget>
#include <QString>
#include <iostream>

#define ROWS 16
#define COLS 36

namespace Ui {
class TinyGame;
}

class TinyGame : public QWidget
{
    Q_OBJECT

public:
    explicit TinyGame(QWidget *parent = 0);
    ~TinyGame();

private slots:
    void on_west_button_clicked();
    void on_north_button_clicked();
    void on_south_button_clicked();
    void on_east_button_clicked();

    void on_quit_button_clicked();

private:

    void draw_board();

    Ui::TinyGame *ui;

    char board[ROWS][COLS];

    int  hero_row;
    int  hero_col;
};

#endif // TINYGAME_H
