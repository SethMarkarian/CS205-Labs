#include "topthreeplayers.h"
#include "ui_topthreeplayers.h"

TopThreePlayers::TopThreePlayers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopThreePlayers)
{
    ui->setupUi(this);
}

TopThreePlayers::~TopThreePlayers()
{
    delete ui;
}

void TopThreePlayers::draw_screen() {
    std::vector<Player * > g = pgh->top_3();
    QString q = "";
    for(int i = 0; i < g.size(); i++) {
        q += i + 1;
        q += ". ";
        q += g[i]->getFirstName();
        q += " ";
        q += g[i]->getLastName();
        q += "\n";
    }
}

void TopThreePlayers::getPGH(PlayerGameHistory *p) {
    pgh = p;
}
