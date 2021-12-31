#pragma once

#include <QWidget>
#include "ui_Log.h"
#include "xxlProject.h"
#include "DButil.h"

class Log : public QWidget
{
	Q_OBJECT

public:
	Log(QWidget *parent = Q_NULLPTR);
	~Log();

private:
	Ui::Log ui;
	xxlProject* xxlproject;
	DButil db;

private slots:
	void on_pushButtonLog_clicked();
	void on_pushButtonReg_clicked();
};
