#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "topthreeplayers.h"
#include "topthreegames.h"
#include "calculatedstatistics.h"
#include "newplayerscreendialog.h"
#include "existingplayerscreendialog.h"
#include <vector>

#include "../History/player.h"
#include "../RobotsGUI/robotsgui.h"
#include "../WormGUI/wormgui.h"
#include <iostream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Player * p;
    PlayerGameHistory * pgh;
    explicit MainWindow(QWidget *parent = nullptr);
    void draw_board();
    ~MainWindow();

private slots:
    void on_actionExit_Program_triggered();

    void on_actionTop_3_Players_triggered();

    void on_actionTop_3_Games_triggered();

    void on_actionCalculated_Statistics_triggered();

    void on_actionNew_Player_triggered();

    void on_actionSelect_Existing_Player_triggered();

    void on_RobotsButton_clicked();

    void on_WormsButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


