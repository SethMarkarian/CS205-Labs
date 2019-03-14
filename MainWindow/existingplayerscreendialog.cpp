#include "existingplayerscreendialog.h"
#include "ui_existingplayerscreendialog.h"
#include "../History/playergamehistory.h"

ExistingPlayerScreenDialog::ExistingPlayerScreenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExistingPlayerScreenDialog)
{
    ui->setupUi(this);
}

ExistingPlayerScreenDialog::~ExistingPlayerScreenDialog()
{
    delete ui;
}

void ExistingPlayerScreenDialog::on_pushButton_clicked()
{
    if(pgh->numPlayers() >= 1) {
        p = pgh->retPlayers().at(0);
    }
    close();
}

void ExistingPlayerScreenDialog::on_pushButton_2_clicked()
{
    if(pgh->numPlayers() >= 2) {
        p = pgh->retPlayers().at(1);
    }
    close();
}

void ExistingPlayerScreenDialog::on_pushButton_3_clicked()
{
    if(pgh->numPlayers() >= 3) {
        p = pgh->retPlayers().at(2);
    }
    close();
}

void ExistingPlayerScreenDialog::on_pushButton_4_clicked()
{
    if(pgh->numPlayers() >= 4) {
        p = pgh->retPlayers().at(3);
    }
    close();
}

void ExistingPlayerScreenDialog::on_pushButton_5_clicked()
{
    if(pgh->numPlayers() >= 5) {
        p = pgh->retPlayers().at(4);
    }
    close();
}

void ExistingPlayerScreenDialog::on_pushButton_6_clicked()
{
    if(pgh->numPlayers() >= 6) {
        p = pgh->retPlayers().at(5);
    }
    close();
}

void ExistingPlayerScreenDialog::on_pushButton_7_clicked()
{
    if(pgh->numPlayers() >= 7) {
        p = pgh->retPlayers().at(6);
    }
    close();
}

void ExistingPlayerScreenDialog::on_pushButton_8_clicked()
{
    if(pgh->numPlayers() >= 8) {
        p = pgh->retPlayers().at(7);
    }
    close();
}

void ExistingPlayerScreenDialog::on_pushButton_9_clicked()
{
    if(pgh->numPlayers() >= 9) {
        p = pgh->retPlayers().at(8);
    }
    close();
}

void ExistingPlayerScreenDialog::on_pushButton_10_clicked()
{
    if(pgh->numPlayers() >= 10) {
        p = pgh->retPlayers().at(9);
    }
    close();
}

void ExistingPlayerScreenDialog::draw_board() {
    if(pgh->numPlayers() >= 1) {
        std::string out;
        out += pgh->retPlayers().at(0)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(0)->getLastName();
        ui->Player1->setText(QString::fromStdString(out));
    }

    if(pgh->numPlayers() >= 2) {
        std::string out;
        out += pgh->retPlayers().at(1)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(1)->getLastName();
        ui->Player2->setText(QString::fromStdString(out));
    }

    if(pgh->numPlayers() >= 3) {
        std::string out;
        out += pgh->retPlayers().at(2)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(2)->getLastName();
        ui->Player3->setText(QString::fromStdString(out));
    }

    if(pgh->numPlayers() >= 4) {
        std::string out;
        out += pgh->retPlayers().at(3)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(3)->getLastName();
        ui->Player4->setText(QString::fromStdString(out));
    }

    if(pgh->numPlayers() >= 5) {
        std::string out;
        out += pgh->retPlayers().at(4)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(4)->getLastName();
        ui->Player5->setText(QString::fromStdString(out));
    }

    if(pgh->numPlayers() >= 6) {
        std::string out;
        out += pgh->retPlayers().at(5)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(5)->getLastName();
        ui->Player6->setText(QString::fromStdString(out));
    }

    if(pgh->numPlayers() >= 7) {
        std::string out;
        out += pgh->retPlayers().at(6)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(6)->getLastName();
        ui->Player7->setText(QString::fromStdString(out));
    }

    if(pgh->numPlayers() >= 8) {
        std::string out;
        out += pgh->retPlayers().at(7)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(7)->getLastName();
        ui->Player8->setText(QString::fromStdString(out));
    }

    if(pgh->numPlayers() >= 9) {
        std::string out;
        out += pgh->retPlayers().at(8)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(8)->getLastName();
        ui->Player9->setText(QString::fromStdString(out));
    }

    if(pgh->numPlayers() >= 10) {
        std::string out;
        out += pgh->retPlayers().at(9)->getFirstName();
        out += " ";
        out += pgh->retPlayers().at(9)->getLastName();
        ui->Player10->setText(QString::fromStdString(out));
    }
}

Player * ExistingPlayerScreenDialog::getPlayer() {
    return p;
}

void ExistingPlayerScreenDialog::setPGH(PlayerGameHistory * p) {
    pgh = p;
}
