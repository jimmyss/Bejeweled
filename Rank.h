#pragma once

#include <QDialog>
//#include "ui_Rank.h"
#include <QTableView>

class Rank : public QTableView //�̳���QTableView
{
	Q_OBJECT

public:
	Rank(QWidget *parent = Q_NULLPTR);
	~Rank();

//private:
	//Ui::Rank ui;
	//void showRank();
};
