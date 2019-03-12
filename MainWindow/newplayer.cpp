#include "newplayer.h"
#include "ui_newplayer.h"

NewPlayer::NewPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPlayer)
{
    ui->setupUi(this);
}

NewPlayer::~NewPlayer()
{
    delete ui;
}

void NewPlayer::on_Enter_clicked()
{
    QString a = ui->FirstName->text();
    std::string b = a.toLocal8Bit().constData();
    char * fn = strcpy(new char[a.length() - 1], b.c_str());
    ret.push_back(fn);

    QString c = ui->LastName->text();
    std::string d = c.toLocal8Bit().constData();
    char * ln = strcpy(new char[d.length() - 1], d.c_str());
    ret.push_back(ln);

    QString e = ui->LastName->text();
    std::string f = e.toLocal8Bit().constData();
    char * ad = strcpy(new char[f.length() - 1], f.c_str());
    ret.push_back(ad);
    close();
}

std::vector<char * > NewPlayer::getNewPlayer() {
    return ret;
}
