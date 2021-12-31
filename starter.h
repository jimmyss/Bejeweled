#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_xxlProject.h"
#include "Game.h"
#include "DButil.h"
#include "Help.h"
#include "Rank.h"
#include "Log.h"

class Starter : public QMainWindow
{
    Q_OBJECT

public:
    Starter(QWidget *parent = Q_NULLPTR);
    void showLog();

private:
    Ui::XXLProjectClass ui;
    Game* game;
    Log* log;
    DButil* db;
    Help* help;
    Rank* rank;
    int score1;
    QString name1;

private slots:
    void on_pushButtonRank_clicked();
    void on_pushButtonHelp_clicked();
    void on_pushButtonStart_clicked();

    void backShow(int score);
    void afterLog(QString& name);
    void afterHelp();
    void afterRank();
};
