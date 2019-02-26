#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>
#include <QFile>
#include <QTextStream>

namespace Ui {
class TextFinder;
}

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = nullptr);
    ~TextFinder();

private slots:
    void on_findButton_clicked();

private:
    Ui::TextFinder *ui;
    void loadTextFile();
};

#endif // TEXTFINDER_H
