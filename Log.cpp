#include "Log.h"

Log::Log(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEditHint->setFocusPolicy(Qt::NoFocus);

	//����Ƥ��
	QPalette PAllbackground = this->palette();
	QImage ImgAllbackground("pictures/style1/background1.jpg");
	QImage fitimgpic = ImgAllbackground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
	PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
	this->setPalette(PAllbackground);

	QString buttonStyle1 = "QPushButton{background-color: rgb(245,212, 217);}" //��ť��ɫ
		"QPushButton::hover{background-color: rgb(249, 204, 226);}" //�����ͣʱ
		"QPushButton::pressed{background-color: rgb(242, 156, 177);}" //�����ť
		"QPushButton{border-style:outset;}"                  //�߿���ʽ��inset/outset��
		"QPushButton{border-width:4px;}"                     //�߿�������
		"QPushButton{border-radius:10px;}"                   //�߿�Բ�ǰ뾶����
		"QPushButton{border-color:rgba(241,158,194,30);}"    //�߿���ɫ
		"QPushButton{font:bold 30px;}"                       //���壬�����С
		"QPushButton{color:rgba(0,0,0,100);}"                //������ɫ
		"QPushButton{padding:6px;}";                          //���

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
