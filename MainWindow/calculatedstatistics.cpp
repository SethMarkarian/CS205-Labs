#include "calculatedstatistics.h"
#include "ui_calculatedstatistics.h"

CalculatedStatistics::CalculatedStatistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatedStatistics)
{
    ui->setupUi(this);
}

CalculatedStatistics::~CalculatedStatistics()
{
    delete ui;
}
