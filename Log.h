#pragma once

//在头文件前面加上下面几行代码
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include <qdialog.h>
#include "ui_Log.h"
#include "DButil.h"
#include <QMessageBox.h>

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
