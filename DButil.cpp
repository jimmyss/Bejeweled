#include "DButil.h"

void DButil::initDB()
{
	QSqlQuery sql_query;
	QString create_sql = "create table player (name varchar(30) primary key, password varchar(30), rank int)";
	sql_query.prepare(create_sql);
	if (!sql_query.exec())
	{
		qDebug() << "Error: Fail to create table." << sql_query.lastError();
	}
	else
	{
		qDebug() << "Table created!";
	}
}

DButil::DButil() { }

int DButil::login(QString name, QString password)
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("PlayerData.db");
	if (!db.open()) {
		qDebug() << "can't open database";
	}
	else
		qDebug() << "successfully open database";

	QSqlQuery sql_query;
	QString select_sql = "select password from player where name = ?";
	sql_query.prepare(select_sql);
	sql_query.addBindValue(name);

	if (!sql_query.exec())
	{
		qDebug() << sql_query.lastError();
		return -1;
	}
	else
	{
		if (!sql_query.next())
			return 0;
		QString pass_to_check = sql_query.value(0).toString();
		if (password == pass_to_check) 
			return 1;
		else
			return 0;
	}

	db.close();
}

int DButil::registrate(QString name, QString password)
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("PlayerData.db");
	if (!db.open()) {
		qDebug() << "can't open database";
	}
	else
		qDebug() << "successfully open database";

	QSqlQuery sql_query;

	QString select_sql = "select name from player where name = ?";
	sql_query.prepare(select_sql);
	sql_query.addBindValue(name);

	if (!sql_query.exec()) {
		qDebug() << sql_query.lastError();
		return -1;
	}
	else {
		if (sql_query.next()) {
			return 0;
		}
	}

	QString insert_sql = "insert into player values (?, ?, ?)";
	sql_query.prepare(insert_sql);
	sql_query.addBindValue(name);
	sql_query.addBindValue(password);
	sql_query.addBindValue(0);
	if (!sql_query.exec())
	{
		qDebug() << sql_query.lastError();
		return -1;
	}
	else
		return 1;
	db.close();
}

int DButil::updateRank(QString name, int rank)
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("PlayerData.db");
	if (!db.open()) {
		qDebug() << "can't open database";
	}
	else
		qDebug() << "successfully open database";

	QSqlQuery sql_query;
	QString update_sql = "update player set rank = :rank where name = :name";
	QString select_sql = "select rank from player where name = ?";

	int historyRank = 0;

	sql_query.prepare(select_sql);
	sql_query.addBindValue(name);

	if (!sql_query.exec()) {
		qDebug() << sql_query.lastError();
		return -1;
	}
	else {
		if (sql_query.next()) {
			historyRank = sql_query.value(0).toInt();
		}
	}

	rank = rank > historyRank ? rank : historyRank;

	sql_query.prepare(update_sql);
	sql_query.bindValue(":rank", rank);
	sql_query.bindValue(":name", name);

	if (!sql_query.exec())
	{
		qDebug() << sql_query.lastError();
		return -1;
	}
	else
		return 1;
	db.close();
}

void DButil::showInfo()
{
}


