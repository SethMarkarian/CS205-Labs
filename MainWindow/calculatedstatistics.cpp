#include "calculatedstatistics.h"
#include "ui_calculatedstatistics.h"

CalculatedStatistics::CalculatedStatistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatedStatistics)
{
    ui->setupUi(this);
    draw_board();
}

CalculatedStatistics::~CalculatedStatistics()
{
    delete ui;
}

void CalculatedStatistics::draw_board() {
    QString as = QString::fromStdString(std::to_string(pgh->avgScore()));
    ui->avgScore->setText(as);

    QString ts = QString::fromStdString(std::to_string(pgh->topScore()));
    ui->topScore->setText(ts);
}

void CalculatedStatistics::getPGH(PlayerGameHistory * p) {
    pgh = p;
}
