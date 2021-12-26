#pragma once
#include <QtSql>

class DButil
{
private:
	QSqlDatabase db;
public:
	DButil();
	~DButil() { db.close(); };

	void initDB();

	int login(QString name, QString password);
	int registrate(QString name, QString password);
	int updateRank(QString name, int rank);
	void showInfo();
};

