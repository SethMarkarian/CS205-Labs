#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_Program_triggered()
{
    close();
}

void MainWindow::on_actionTop_3_Players_triggered()
{
    TopThreePlayers *ttp = new TopThreePlayers();
    ttp->show();
    hide();
}

void MainWindow::on_actionTop_3_Games_triggered()
{

}

void MainWindow::on_actionCalculated_Statistics_triggered()
{

}

void MainWindow::on_actionNew_Player_triggered()
{

}

void MainWindow::on_actionSelect_Existing_Player_triggered()
{

}

//HELPFUL STUFF
//QWidget *wdg = new QWidget;
//wdg->show();
//hide();//this will disappear main window
