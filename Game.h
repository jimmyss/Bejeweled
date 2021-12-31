#pragma once

#include <QtWidgets/QWidget>
#include "ui_Game.h"
#include <QPropertyAnimation>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QTimer>
#include<QPalette>
#include<ctime>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <qmessagebox.h>
#include<qdebug.h>
#include"Gem.h"
#include"rule.h"

#define BLOCK_LENGTH 20;

class Game : public QWidget
{
	Q_OBJECT

public:
	Game(QWidget* parent = Q_NULLPTR);
	~Game();
	QPropertyAnimation* fallAnimation(Gem* gem, int h, int flag);
	void setGems(int x, int y, int type);
	void switchBlock();
	QParallelAnimationGroup* clearBlock();
	QParallelAnimationGroup* fallBlock();
	void generatGems();
	void resetBlock();
	static void explodesound() {
		PlaySound(TEXT("explode.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	static void clicksound() {
		PlaySound(TEXT("click.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}

protected:
	virtual void mousePressEvent(QMouseEvent* event);
private:
	Ui::Game ui;
	int roundNumber=0;
	int click_x, click_y;
	int move_x1, move_x2, move_y1, move_y2;
	int g1y, g1x, g2y, g2x;
	int gCounter = 0;//用于记录点了多少次方块，点两次时执行交换
	bool endFlag = true;//endFlag为true表示可以结束，否则表示不能结束
	bool check = false;
	vector<vector<int>> fallMatrix;
	vector<vector<int>> generateMatrix;
	vector<vector<int>> deleteMatrix;
	Gem* g1;
	Gem* g2;//2021-12-21 杜世茂 g1和g2分别表示两个块块儿
	Gem* gems[10][10];
	Bejewled* rule;//2021-12-21 杜世茂 rule实例
	QTimer* runtime;
	void move(int x1, int y1, int x2, int y2);
	int paintState;

private slots:
	void on_pushButtonFinish_clicked();
	void on_pushButtonHint_clicked();
	void buttonClicked();
signals:
	void backSignal();
};
