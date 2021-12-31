#include "Rank.h"
#include<QFile>

#include <QTableView>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>
#include "QtSql/QsqlQueryModel"
#include "QDebug"
#include "QModelIndex"

Rank::Rank(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

	db.setDatabaseName("PlayerData.db");

	if (!db.open())
	{
		qDebug() << "mistake"; //´íÎó´¦Àí
	}

	static QSqlQueryModel* model = new QSqlQueryModel(ui.tableView);
	model->setQuery(QString("select * from player"));
	ui.tableView->setModel(model);
	ui.tableView->setColumnHidden(1, true);
	db.close();
}

Rank::~Rank()
{
}
void Rank::showRank() {

}


