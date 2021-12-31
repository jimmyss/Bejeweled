#include "xxlProject.h"
#include "Help.h"
#include "Rank.h"
#include "QMessageBox"

xxlProject::xxlProject(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // 播放音乐
    //PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    //设置皮肤
    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground("pictures/style1/background1.jpg");
    QImage fitimgpic = ImgAllbackground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
    this->setPalette(PAllbackground);

    QString buttonStyle1 = "QPushButton{background-color: rgb(245,212, 217);}" //按钮颜色
        "QPushButton::hover{background-color: rgb(249, 204, 226);}" //鼠标悬停时
        "QPushButton::pressed{background-color: rgb(242, 156, 177);}" //点击按钮
        "QPushButton{border-style:outset;}"                  //边框样式（inset/outset）
        "QPushButton{border-width:4px;}"                     //边框宽度像素
        "QPushButton{border-radius:10px;}"                   //边框圆角半径像素
        "QPushButton{border-color:rgba(241,158,194,30);}"    //边框颜色
        "QPushButton{font:bold 30px;}"                       //字体，字体大小
        "QPushButton{color:rgba(0,0,0,100);}"                //字体颜色
        "QPushButton{padding:6px;}";                          //填衬

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
    XXL->show();//program窗口显示
    this->close();//本窗口隐藏
}
