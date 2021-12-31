#include "Log.h"

Log::Log(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//设置皮肤
	QPalette PAllbackground = this->palette();
	QImage ImgAllbackground("pictures/style1/background1.jpg");
	QImage fitimgpic = ImgAllbackground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
	PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
	this->setPalette(PAllbackground);

	// 设置按钮样式
	QString buttonStyle1 = "QPushButton{background-color: rgb(245,212, 217);}" //按钮颜色
		"QPushButton::hover{background-color: rgb(249, 204, 226);}" //鼠标悬停时
		"QPushButton::pressed{background-color: rgb(242, 156, 177);}" //点击按钮
		"QPushButton{border-style:outset;}"                  //边框样式（inset/outset）
		"QPushButton{border-width:4px;}"                     //边框宽度像素
		"QPushButton{border-radius:10px;}"                   //边框圆角半径像素
		"QPushButton{border-color:rgba(241,158,194,30);}"    //边框颜色
		"QPushButton{font:bold 15px;}"                       //字体，字体大小
		"QPushButton{color:rgba(0,0,0,100);}"                //字体颜色
		"QPushButton{padding:6px;}";     //填衬

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
		ui.lineEditHint->setText("用户名不能为空！");
		//QMessageBox::about(NULL, "警告", "用户名不能为空！");
		return;
	}
	else if (password.isEmpty()) {
		ui.lineEditHint->setText("密码不能为空！");
		//QMessageBox::about(NULL, "警告", "密码不能为空！");
		return;
	}
	else {
		res = db->login(name, password);
	}


	if (res == -1) {
		ui.lineEditHint->setText("操作失败，请再次尝试");
		//QMessageBox::about(NULL, "警告", "错误！");

	}
	if (res == 0) {
		ui.lineEditHint->setText("用户名或密码错误");
		//QMessageBox::about(NULL, "警告", "用户名或密码错误");

	}
	if (res == 1) {
		//登录成功做跳转
		emit toStarter();
	}
}
void Log::on_pushButtonReg_clicked() {
	QString name = ui.lineEditName->text();
	QString password = ui.lineEditPassword->text();

	int res;

	if (name.isEmpty()) {
		ui.lineEditHint->setText("用户名不能为空！");
		//QMessageBox::about(NULL, "警告", "用户名不能为空！");
		return;
	}
	else if (password.isEmpty()) {
		ui.lineEditHint->setText("密码不能为空！");
		//QMessageBox::about(NULL, "警告", "密码不能为空！");
		return;
	}
	else {
		res = db->login(name, password);
	}

	if (res == -1) {
		ui.lineEditHint->setText("操作失败，请再次尝试");
		//QMessageBox::about(NULL, "警告", "错误！");

	}
	if (res == 0) {
		ui.lineEditHint->setText("用户名重复！");
		//QMessageBox::about(NULL, "警告", "用户名重复！");

	}
	if (res == 1) {
		ui.lineEditHint->setText("注测成功！");
		//QMessageBox::about(NULL, "提示", "注测成功！");

	}
}


