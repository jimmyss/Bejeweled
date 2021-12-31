#pragma once

#include <QDialog>
#include "ui_Rank.h"
#include "DButil.h"

class Rank : public QDialog
{
	Q_OBJECT

public:
	Rank(QWidget *parent = Q_NULLPTR);
	~Rank();
	void setDB(DButil* db);
protected:
	virtual void closeEvent(QCloseEvent* event);
private:
	Ui::Rank ui;
	DButil* db;
	void showRank();
signals:
	void backToMain();
};
