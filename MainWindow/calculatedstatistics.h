#ifndef CALCULATEDSTATISTICS_H
#define CALCULATEDSTATISTICS_H

#include <QWidget>

namespace Ui {
class CalculatedStatistics;
}

class CalculatedStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatedStatistics(QWidget *parent = nullptr);
    ~CalculatedStatistics();

private:
    Ui::CalculatedStatistics *ui;
};

#endif // CALCULATEDSTATISTICS_H
