#include "Rank.h"
#include<QFile>
#include <QSqlTableModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QDebug>

Rank::Rank(QWidget *parent)
	: QTableView(parent)
{
	//ui.setupUi(this);
	//QPalette pal = this->palette();
	//pal.setBrush(QPalette::Base, QBrush(QPixmap("pictures/recordbackground.jpg")));
	//setPalette(pal);
	//showRank();

	//��qtableviewչʾ���а�
	QStandardItemModel* model = new QStandardItemModel(this);
	model->setItem(0, 0, new QStandardItem("����"));
	model->setItem(0, 1, new QStandardItem("3"));
	model->setItem(0, 2, new QStandardItem("��"));
	this->setModel(model);
}

Rank::~Rank()
{

}

//void Rank::showRank() 
//{
//	QFile f("./Rank.txt");
//	QString displayString;
//	if (!f.open(QIODevice::ReadOnly | QIODevice::Text))//��ָ���ļ�
//	{
//		ui.textEdit->append("not successful");
//	}
//
//	while (!f.atEnd())
//	{
//		QByteArray line = f.readLine();
//		QString str(line);
//		displayString.append(str);
//	}
//
//	ui.textEdit->setText(displayString);
//	f.close();
//
	//��qtableviewչʾ���а�
	//QStandardItemModel* model = new QStandardItemModel(this);
	//model->setItem(0, 0, new QStandardItem("����"));
	//model->setItem(0, 1, new QStandardItem("3"));
	//model->setItem(0, 2, new QStandardItem("��"));
	//this->setModal(model);
//}
//
//
