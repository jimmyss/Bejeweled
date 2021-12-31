#pragma once

#include <qdialog.h>
#include "ui_Log.h"
#include "DButil.h"

class Log : public QDialog
{
	Q_OBJECT
public:
	Log(QWidget *parent = Q_NULLPTR);
	~Log();

	void setDB(DButil* db);

private:
	Ui::Log ui;
	DButil* db;
signals:
	void toStarter();
private slots:
	void on_pushButtonLog_clicked();
	void on_pushButtonReg_clicked();
};
