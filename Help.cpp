#include "Help.h"

Help::Help(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QPalette pal = this->palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap("pictures/dialog_bg.png")));
	setPalette(pal);
}

Help::~Help()
{
}
