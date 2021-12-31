#include "xxlProject.h"
#include "Help.h"
#include "Rank.h"
#include "QMessageBox"

xxlProject::xxlProject(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // ��������
    //PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

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

    ui.pushButtonStart->setStyleSheet(buttonStyle1);
    ui.pushButtonRank->setStyleSheet(buttonStyle1);
    ui.pushButtonHelp->setStyleSheet(buttonStyle1);
}
void xxlProject::on_pushButtonRank_clicked() {
    Rank* rank = new Rank();
    rank->exec();
}
void xxlProject::on_pushButtonHelp_clicked() {
    Help* help = new Help();
    help->exec();
}
void xxlProject::on_pushButtonStart_clicked() {
    game = new Game;
    game->show();
    this->hide();
}
void Game::on_pushButtonFinish_clicked()
{
    QMessageBox message(QMessageBox::NoIcon, "Tip", "Back successfully ");
    message.exec();
    xxlProject* XXL = new xxlProject;
    XXL->show();//program������ʾ
    this->close();//����������
}
