#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p = new Player(nullptr, nullptr, nullptr, nullptr);
    //g = nullptr;
    draw_board();
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
}

void MainWindow::on_actionTop_3_Games_triggered()
{
    TopThreeGames *ttg = new TopThreeGames();
    ttg->show();
}

void MainWindow::on_actionCalculated_Statistics_triggered()
{
    CalculatedStatistics *cs = new CalculatedStatistics();
    cs->show();
}

void MainWindow::on_actionNew_Player_triggered()
{
    NewPlayer *np = new NewPlayer();
    np->show();
    std::vector<char * > player = np->getNewPlayer();
    //p = new Player(g, player[0], player[1], player[2]);
    draw_board();
}

void MainWindow::on_actionSelect_Existing_Player_triggered()
{

}

void MainWindow::draw_board() {
    QString s = "";

    if(p != nullptr) {
        s += p->getFirstName();
        s += " ";
        s += p->getLastName();
    }
    else {
        s += "No Player Selected";
    }
    ui->PlayerName->clear();
    ui->PlayerName->setText(s);
}

//HELPFUL STUFF
//QWidget *wdg = new QWidget;
//wdg->show();
//hide();//this will disappear main window
