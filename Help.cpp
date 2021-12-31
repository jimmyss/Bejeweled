#include "Help.h"

Help::Help(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QPalette PAllbackground = this->palette();
	QImage ImgAllbackground("pictures/style1/bg.jpg");
	QImage fitimgpic = ImgAllbackground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
	PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
	this->setPalette(PAllbackground);

	//���ñ���͸��
	QPalette pl = ui.helpText->palette();
	pl.setBrush(QPalette::Base, QBrush(QColor(255, 0, 0, 0)));
	ui.helpText->setPalette(pl);
}

Help::~Help()
{
}

//��дclose�¼�
void Help::closeEvent(QCloseEvent* event) {
	emit backToMain();
}
