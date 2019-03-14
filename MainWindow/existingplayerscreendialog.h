#ifndef EXISTINGPLAYERSCREENDIALOG_H
#define EXISTINGPLAYERSCREENDIALOG_H

#include <QDialog>
#include "../History/player.h"
#include "../History/playergamehistory.h"

namespace Ui {
class ExistingPlayerScreenDialog;
}

class ExistingPlayerScreenDialog : public QDialog
{
    Q_OBJECT

public:
    PlayerGameHistory * pgh;
    Player * p;
    explicit ExistingPlayerScreenDialog(QWidget *parent = nullptr);
    ~ExistingPlayerScreenDialog();
    Player * getPlayer();
    void setPGH(PlayerGameHistory * p);
    void draw_board();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();





private:
    Ui::ExistingPlayerScreenDialog *ui;
};

#endif // EXISTINGPLAYERSCREENDIALOG_H
