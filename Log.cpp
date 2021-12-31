#include "Log.h"

Log::Log(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//����Ƥ��
	QPalette PAllbackground = this->palette();
	QImage ImgAllbackground("pictures/style1/background1.jpg");
	QImage fitimgpic = ImgAllbackground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
	PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
	this->setPalette(PAllbackground);

	// ���ð�ť��ʽ
	QString buttonStyle1 = "QPushButton{background-color: rgb(245,212, 217);}" //��ť��ɫ
		"QPushButton::hover{background-color: rgb(249, 204, 226);}" //�����ͣʱ
		"QPushButton::pressed{background-color: rgb(242, 156, 177);}" //�����ť
		"QPushButton{border-style:outset;}"                  //�߿���ʽ��inset/outset��
		"QPushButton{border-width:4px;}"                     //�߿�������
		"QPushButton{border-radius:10px;}"                   //�߿�Բ�ǰ뾶����
		"QPushButton{border-color:rgba(241,158,194,30);}"    //�߿���ɫ
		"QPushButton{font:bold 15px;}"                       //���壬�����С
		"QPushButton{color:rgba(0,0,0,100);}"                //������ɫ
		"QPushButton{padding:6px;}";     //���

	ui.lineEditHint->setText("welcome! :)");

	ui.pushButtonLog->setStyleSheet(buttonStyle1);
	ui.pushButtonReg->setStyleSheet(buttonStyle1);

	//ui.lineEditHint->setFocusPolicy(Qt::NoFocus);
}

Log::~Log()
{
}

void Log::setDB(DButil* db)
{
	this->db = db;
}

void Log::on_pushButtonLog_clicked() {

	QString name = ui.lineEditName->text();
	QString password = ui.lineEditPassword->text();

	int res = -1;

	if (name.isEmpty()) {
		ui.lineEditHint->setText("�û�������Ϊ�գ�");
		//QMessageBox::about(NULL, "����", "�û�������Ϊ�գ�");
		return;
	}
	else if (password.isEmpty()) {
		ui.lineEditHint->setText("���벻��Ϊ�գ�");
		//QMessageBox::about(NULL, "����", "���벻��Ϊ�գ�");
		return;
	}
	else {
		res = db->login(name, password);
	}


	if (res == -1) {
		ui.lineEditHint->setText("����ʧ�ܣ����ٴγ���");
		//QMessageBox::about(NULL, "����", "����");

	}
	if (res == 0) {
		ui.lineEditHint->setText("�û������������");
		//QMessageBox::about(NULL, "����", "�û������������");

	}
	if (res == 1) {
		//��¼�ɹ�����ת
		emit toStarter();
	}
}
void Log::on_pushButtonReg_clicked() {
	QString name = ui.lineEditName->text();
	QString password = ui.lineEditPassword->text();

	int res;

	if (name.isEmpty()) {
		ui.lineEditHint->setText("�û�������Ϊ�գ�");
		//QMessageBox::about(NULL, "����", "�û�������Ϊ�գ�");
		return;
	}
	else if (password.isEmpty()) {
		ui.lineEditHint->setText("���벻��Ϊ�գ�");
		//QMessageBox::about(NULL, "����", "���벻��Ϊ�գ�");
		return;
	}
	else {
		res = db->login(name, password);
	}

	if (res == -1) {
		ui.lineEditHint->setText("����ʧ�ܣ����ٴγ���");
		//QMessageBox::about(NULL, "����", "����");

	}
	if (res == 0) {
		ui.lineEditHint->setText("�û����ظ���");
		//QMessageBox::about(NULL, "����", "�û����ظ���");

	}
	if (res == 1) {
		ui.lineEditHint->setText("ע��ɹ���");
		//QMessageBox::about(NULL, "��ʾ", "ע��ɹ���");

	}
}


