#include "Rank.h"
#include<QFile>

Rank::Rank(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QPalette pal = this->palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap("pictures/recordbackground.jpg")));
	setPalette(pal);
	showRank();
}

Rank::~Rank()
{
}
void Rank::showRank() {
	QFile f("./Rank.txt");
	QString displayString;
	if (!f.open(QIODevice::ReadOnly | QIODevice::Text))//打开指定文件
	{
		ui.textEdit->append("not successful");
	}

	while (!f.atEnd())
	{
		QByteArray line = f.readLine();
		QString str(line);
		displayString.append(str);
	}

	ui.textEdit->setText(displayString);
	f.close();
}


