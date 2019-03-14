#ifndef TOPTHREEGAMES_H
#define TOPTHREEGAMES_H

#include <QWidget>
#include "../History/playergamehistory.h"
#include "../History/game.h"
#include <vector>

namespace Ui {
class TopThreeGames;
}

class TopThreeGames : public QWidget
{
    Q_OBJECT
    PlayerGameHistory * pgh;

public:
    explicit TopThreeGames(QWidget *parent = nullptr);
    ~TopThreeGames();
    void draw_screen();
    void getPGH(PlayerGameHistory * p);

private:
    Ui::TopThreeGames *ui;
};

#endif // TOPTHREEGAMES_H
