#include "xxlProject.h"
#include "Help.h"
#include "Rank.h"
#include "QMessageBox"

xxlProject::xxlProject(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
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
