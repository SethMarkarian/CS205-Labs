#include "topthreegames.h"
#include "ui_topthreegames.h"

TopThreeGames::TopThreeGames(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopThreeGames)
{
    ui->setupUi(this);
}

TopThreeGames::~TopThreeGames()
{
    delete ui;
}
