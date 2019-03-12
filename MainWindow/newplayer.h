#ifndef NEWPLAYER_H
#define NEWPLAYER_H

#include <QWidget>
#include <vector>

namespace Ui {
class NewPlayer;
}

class NewPlayer : public QWidget
{
    Q_OBJECT

    std::vector<char *> ret;

public:
    explicit NewPlayer(QWidget *parent = nullptr);
    std::vector<char * > getNewPlayer();
    ~NewPlayer();

private slots:
    void on_Enter_clicked();

private:
    Ui::NewPlayer *ui;
};

#endif // NEWPLAYER_H
