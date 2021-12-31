#include "Log.h"

Log::Log(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEditHint->setFocusPolicy(Qt::NoFocus);
}

Log::~Log()
{
}

void Log::on_pushButtonLog_clicked() {
	QString name = ui.lineEditName->text();
	QString password = ui.lineEditPassword->text();
	int res = db.login(name, password);
	if (res == -1) {
		ui.lineEditHint->setText("error");
	}
	if (res == 0) {
		ui.lineEditHint->setText("wrong pass/not registrate");
	}
	if (res == 1) {
		//��¼�ɹ�����ת
		xxlproject = new xxlProject;
		xxlproject->show();
		this->hide();
	}
}
void Log::on_pushButtonReg_clicked() {
	QString name = ui.lineEditName->text();
	QString password = ui.lineEditPassword->text();

	int res = db.registrate(name, password);
	if (res == -1) {
		ui.lineEditHint->setText("error");
	}
	if (res == 0) {
		ui.lineEditHint->setText("same name");
	}
	if (res == 1) {
		ui.lineEditHint->setText("regs");
	}
}

