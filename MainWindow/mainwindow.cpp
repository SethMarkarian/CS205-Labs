#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p = new Player(nullptr, nullptr, nullptr, nullptr);
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
    NewPlayerScreenDialog *npsd = new NewPlayerScreenDialog;
    //np->show();
    if(npsd->exec()) {
        npsd->show();
        p = npsd->getNewPlayer();

    }
    //p = np->getNewPlayer();
    //p = new Player(nullptr, "hi", "bye", "hi");
    draw_board();
}

void MainWindow::on_actionSelect_Existing_Player_triggered()
{
    ExistingPlayerScreenDialog * epsd = new ExistingPlayerScreenDialog;
    epsd->setPGH(pgh);
    if(epsd->exec()) {
        epsd->show();
        p = epsd->getPlayer();
    }
    draw_board();
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
