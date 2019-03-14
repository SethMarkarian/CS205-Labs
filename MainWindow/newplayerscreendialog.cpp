#include "newplayerscreendialog.h"
#include "ui_newplayerscreendialog.h"

NewPlayerScreenDialog::NewPlayerScreenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPlayerScreenDialog)
{
    ui->setupUi(this);
}

NewPlayerScreenDialog::~NewPlayerScreenDialog()
{
    delete ui;
}

void NewPlayerScreenDialog::on_Enter_clicked()
{
    QString a = ui->FirstName->text();
    std::string b = a.toLocal8Bit().constData();
    char * fn = strcpy(new char[a.length() - 1], b.c_str());
    ret.push_back(fn);

    QString c = ui->LastName->text();
    std::string d = c.toLocal8Bit().constData();
    char * ln = strcpy(new char[d.length() - 1], d.c_str());
    ret.push_back(ln);

    QString e = ui->Address->text();
    std::string f = e.toLocal8Bit().constData();
    char * ad = strcpy(new char[f.length() - 1], f.c_str());
    ret.push_back(ad);

    close();
}

Player * NewPlayerScreenDialog::getNewPlayer() {
    return new Player(nullptr, ret[0], ret[1], ret[2]);
}
