#ifndef NEWPLAYERSCREENDIALOG_H
#define NEWPLAYERSCREENDIALOG_H

#include <QDialog>
#include <vector>
#include "../History/player.h"

namespace Ui {
class NewPlayerScreenDialog;
}

class NewPlayerScreenDialog : public QDialog
{
    Q_OBJECT

    std::vector<char *> ret;

public:
    explicit NewPlayerScreenDialog(QWidget *parent = nullptr);
    Player * getNewPlayer();
    ~NewPlayerScreenDialog();

private slots:
    void on_Enter_clicked();

private:
    Ui::NewPlayerScreenDialog *ui;
};

#endif // NEWPLAYERSCREENDIALOG_H
