#include "starter.h"

Starter::Starter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    db = new DButil;
    log = new Log(this);
    log->setDB(db);
    help = new Help(this);
    rank = new Rank(this);
    rank->setDB(db);
    help->hide();
    rank->hide();
    connect(rank, SIGNAL(backToMain()), this, SLOT(afterRank()));
    connect(help, SIGNAL(backToMain()), this, SLOT(afterHelp()));
    connect(log, SIGNAL(toStarter()), this, SLOT(afterLog()));

    // ²¥·ÅÒôÀÖ
    //PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    //ÉèÖÃÆ¤·ô
    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground("pictures/style1/background1.jpg");
    QImage fitimgpic = ImgAllbackground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
    this->setPalette(PAllbackground);

    QString buttonStyle1 = "QPushButton{background-color: rgb(245,212, 217);}" //°´Å¥ÑÕÉ«
        "QPushButton::hover{background-color: rgb(249, 204, 226);}" //Êó±êĞüÍ£Ê±
        "QPushButton::pressed{background-color: rgb(242, 156, 177);}" //µã»÷°´Å¥
        "QPushButton{border-style:outset;}"                  //±ß¿òÑùÊ½£¨inset/outset£©
        "QPushButton{border-width:4px;}"                     //±ß¿ò¿í¶ÈÏñËØ
        "QPushButton{border-radius:10px;}"                   //±ß¿òÔ²½Ç°ë¾¶ÏñËØ
        "QPushButton{border-color:rgba(241,158,194,30);}"    //±ß¿òÑÕÉ«
        "QPushButton{font:bold 20px;}"                       //×ÖÌå£¬×ÖÌå´óĞ¡
        "QPushButton{color:rgba(0,0,0,100);}"                //×ÖÌåÑÕÉ«
        "QPushButton{padding:6px;}";                          //Ìî³Ä

    ui.pushButtonStart->setStyleSheet(buttonStyle1);
    ui.pushButtonRank->setStyleSheet(buttonStyle1);
    ui.pushButtonHelp->setStyleSheet(buttonStyle1);
}

void Starter::on_pushButtonRank_clicked() {
    
    rank->show();
}

void Starter::showLog()
{
    log->show();
    this->hide();
}

void Starter::on_pushButtonHelp_clicked() {
    
    help->show();
}

void Starter::on_pushButtonStart_clicked() {
    game = new Game();
    connect(game, SIGNAL(backSignal()), this, SLOT(backShow()));
    this->hide();
    game->show();
}

void Starter::backShow()
{
    this->show();
    game->close();
}

void Starter::afterLog()
{
    this->show();
    log->hide();
}

void Starter::afterHelp()
{
    //this->show();
    help->hide();
}

void Starter::afterRank()
{
    //this->show();
    rank->hide();
}