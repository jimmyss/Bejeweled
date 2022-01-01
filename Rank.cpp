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

	setAttribute(Qt::WA_DeleteOnClose);

	QSqlQueryModel* model = new QSqlQueryModel(ui.tableView);
	model->setQuery(QString("select * from player"));
	ui.tableView->setModel(model);
	ui.tableView->setColumnHidden(1, true);

	// ����tableView��ɫ
	ui.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(245,212, 217);font:13pt '����';color: black;};");
	ui.tableView->setStyleSheet("selection-background-color:pink;"); //����ѡ�б���ɫ
}

Rank::~Rank()
{
}

void Rank::setDB(DButil* db)
{
	this->db = db;
}

void Rank::closeEvent(QCloseEvent* event) {
	emit backToMain();
}

void Rank::showRank()
{
}
