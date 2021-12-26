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

DButil::DButil()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("PlayerData.db");
	if (!db.open()) {
		qDebug() << "can't open database";
	}
	else
		qDebug() << "successfully open database";
}

int DButil::login(QString name, QString password)
{

	qDebug() << name;
	qDebug() << password;

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
}

int DButil::registrate(QString name, QString password)
{
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
}

int DButil::updateRank(QString name, int rank)
{
	QSqlQuery sql_query;
	QString update_sql = "update player set rank = :rank where name = :name";
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
}

void DButil::showInfo()
{
}


