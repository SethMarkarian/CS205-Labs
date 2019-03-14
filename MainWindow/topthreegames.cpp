#include "topthreegames.h"
#include "ui_topthreegames.h"

TopThreeGames::TopThreeGames(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopThreeGames)
{
    ui->setupUi(this);
    draw_screen();
}

TopThreeGames::~TopThreeGames()
{
    delete ui;
}

void TopThreeGames::draw_screen() {
    std::vector<Game * > g = pgh->top_3_games();
    QString q = "";
    for(int i = 0; i < g.size(); i++) {
        q += i + 1;
        q += ". ";
        q += g[i]->getName();
        q += " ";
        q += g[i]->getFinalScore();
        q += "\n";
    }
    ui->label_2->clear();
    ui->label_2->setText(q);
}

void TopThreeGames::getPGH(PlayerGameHistory *p) {
    pgh = p;
}
