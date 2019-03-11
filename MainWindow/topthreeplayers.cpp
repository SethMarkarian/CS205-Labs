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
