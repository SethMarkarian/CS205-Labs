#ifndef CALCULATEDSTATISTICS_H
#define CALCULATEDSTATISTICS_H

#include <QWidget>
#include "../History/playergamehistory.h"

namespace Ui {
class CalculatedStatistics;
}

class CalculatedStatistics : public QWidget
{
    Q_OBJECT
    PlayerGameHistory * pgh;

public:
    explicit CalculatedStatistics(QWidget *parent = nullptr);
    ~CalculatedStatistics();
    void draw_board();
    void getPGH(PlayerGameHistory * p);

private:
    Ui::CalculatedStatistics *ui;
};

#endif // CALCULATEDSTATISTICS_H
