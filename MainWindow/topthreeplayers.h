#ifndef TOPTHREEPLAYERS_H
#define TOPTHREEPLAYERS_H

#include <QWidget>

namespace Ui {
class TopThreePlayers;
}

class TopThreePlayers : public QWidget
{
    Q_OBJECT

public:
    explicit TopThreePlayers(QWidget *parent = nullptr);
    ~TopThreePlayers();

private:
    Ui::TopThreePlayers *ui;
};

#endif // TOPTHREEPLAYERS_H
