#pragma once

//播放音乐需要
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")

//界面
#include <QtWidgets/QMainWindow>
#include "ui_xxlProject.h"
#include "Game.h"

class xxlProject : public QMainWindow
{
    Q_OBJECT

public:
    xxlProject(QWidget *parent = Q_NULLPTR);

private:
    Ui::XXLProjectClass ui;
    Game* game;
private slots:
    void on_pushButtonRank_clicked();
    void on_pushButtonHelp_clicked();
    void on_pushButtonStart_clicked();
};
