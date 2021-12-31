#include "Log.h"

Log::Log(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEditHint->setFocusPolicy(Qt::NoFocus);

	//ÉèÖÃÆ¤·ô
	QPalette PAllbackground = this->palette();
	QImage ImgAllbackground("pictures/style1/background1.jpg");
	QImage fitimgpic = ImgAllbackground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
	PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
	this->setPalette(PAllbackground);

	QString buttonStyle1 = "QPushButton{background-color: rgb(245,212, 217);}" //°´Å¥ÑÕÉ«
		"QPushButton::hover{background-color: rgb(249, 204, 226);}" //Êó±êÐüÍ£Ê±
		"QPushButton::pressed{background-color: rgb(242, 156, 177);}" //µã»÷°´Å¥
		"QPushButton{border-style:outset;}"                  //±ß¿òÑùÊ½£¨inset/outset£©
		"QPushButton{border-width:4px;}"                     //±ß¿ò¿í¶ÈÏñËØ
		"QPushButton{border-radius:10px;}"                   //±ß¿òÔ²½Ç°ë¾¶ÏñËØ
		"QPushButton{border-color:rgba(241,158,194,30);}"    //±ß¿òÑÕÉ«
		"QPushButton{font:bold 30px;}"                       //×ÖÌå£¬×ÖÌå´óÐ¡
		"QPushButton{color:rgba(0,0,0,100);}"                //×ÖÌåÑÕÉ«
		"QPushButton{padding:6px;}";                          //Ìî³Ä

	ui.pushButtonLog->setStyleSheet(buttonStyle1);
	ui.pushButtonReg->setStyleSheet(buttonStyle1);
}

Log::~Log()
{
}
void Log::on_pushButtonLog_clicked() {
	QString name = ui.lineEditName->text();
	QString password = ui.lineEditPassword->text();
	int res = db.login(name, password);
	if (res == -1){
		ui.lineEditHint->setText("error");
	}
	if (res == 0) {
		ui.lineEditHint->setText("wrong pass/not registrate");
	}
	if (res == 1) {
		//µÇÂ¼³É¹¦×öÌø×ª
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
