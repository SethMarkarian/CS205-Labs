#ifndef TOPTHREEGAMES_H
#define TOPTHREEGAMES_H

#include <QWidget>

namespace Ui {
class TopThreeGames;
}

class TopThreeGames : public QWidget
{
    Q_OBJECT

public:
    explicit TopThreeGames(QWidget *parent = nullptr);
    ~TopThreeGames();

private:
    Ui::TopThreeGames *ui;
};

#endif // TOPTHREEGAMES_H
