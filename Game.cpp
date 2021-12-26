#include "Game.h"

Game::Game(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    runtime = new QTimer(this);
    rule = new Bejewled();
    connect(runtime, SIGNAL(timeout()), this, SLOT(update()));
    //设置背景图片
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Base, QBrush(QPixmap("pictures/background.png")));
    setPalette(pal);
    srand((int)time(0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int rNum = rand() % 7;
            gems[i][j] = new Gem(rNum, 42, j, i, this);
            rule->setGraph(i, j, rNum);
            connect(gems[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));//信号0
        }
    }
}

Game::~Game()
{
}
void Game::on_pushButtonHint_clicked() {
    move(1, 6, 1, 7);
}

void Game::mousePressEvent(QMouseEvent* event) {//(20,100)-(230,320)
    click_x = event->x();
    click_y = event->y();
    if (20 < click_x < 100 && 230 < click_y < 320) {
        click_x = (click_x - 20) / 42;
        click_y = (click_y - 100) / 42;
    }
    //paintState = 1;
    //update(30, 110, 42, 42);
}
//一格的移动

//move
void Game::move(int x1, int y1, int x2, int y2) {//(20,100)-(440,520)内 （x1,y1）移动到（x2，y2）
    move_x1 = x1;
    move_x2 = x2;
    move_y1 = y1;
    move_y2 = y2;
    paintState = 1;
    update();
    update();
}

void Game::fallAnimation(Gem* gem, int h, int flag) {
    QPropertyAnimation* animation = new QPropertyAnimation(gem, "geometry", this);
    animation->setDuration(500);
    animation->setStartValue(gem->geometry());
    switch (flag)
    {
        //上
    case 1:
        animation->setEndValue(QRect(gem->geometry().x(), gem->geometry().y() - 42 * h, gem->width(), gem->height()));
        break;
        //下
    case 2:
        animation->setEndValue(QRect(gem->geometry().x(), gem->geometry().y() + 42 * h, gem->width(), gem->height()));
        break;
        //左
    case 3:
        animation->setEndValue(QRect(gem->geometry().x() - 42 * h, gem->geometry().y(), gem->width(), gem->height()));
        break;
        //右
    case 4:
        animation->setEndValue(QRect(gem->geometry().x() + 42 * h, gem->geometry().y(), gem->width(), gem->height()));
        break;
    default:
        break;
    }
    animation->setEasingCurve(QEasingCurve::InQuad);
    animation->start();
    QTimer::singleShot(1000, this, [=]() {
        delete animation;
        });
}

void Game::buttonClicked() {//2021-12-21 杜世茂 buttonClicked原内容改成将选中的两个块块儿传给rule判断是否可执行
    if (gCounter == 0) {
        g1 = qobject_cast<Gem*>(sender());//把信号的发送者转换成pushbutton类型
        gCounter = 1;
    }
    else if (gCounter == 1) {
        g2 = qobject_cast<Gem*>(sender());
        rule->swap(g1->y(), g1->x(), g2->y(), g2->x());
        gCounter = 0;
    }
    //fallAnimation(tb, 1,3);
}

