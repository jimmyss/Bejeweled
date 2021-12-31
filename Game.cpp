#include "Game.h"

Game::Game(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    runtime = new QTimer(this);
    rule = new Bejewled();
    connect(runtime, SIGNAL(timeout()), this, SLOT(update()));

    //���ñ���ͼƬ
    //QPalette pal = this->palette();
    //pal.setBrush(QPalette::Base, QBrush(QPixmap("pictures/background.png")));
    //setPalette(pal);
    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground("pictures/style1/bg.jpg");
    QImage fitimgpic = ImgAllbackground.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
    this->setPalette(PAllbackground);


    srand((int)time(0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int rNum = rand() % 7;
            rule->setGraph(i, j, rNum);
            rule->adjust();
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            gems[i][j] = new Gem(rule->getGraph(i, j), 42, j, i, this);
            connect(gems[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));//�ź�0
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
//һ����ƶ�

//move
void Game::move(int x1, int y1, int x2, int y2) {//(20,100)-(440,520)�� ��x1,y1���ƶ�����x2��y2��
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
        //��
    case 1:
        animation->setEndValue(QRect(gem->geometry().x(), gem->geometry().y() - 42 * h, gem->width(), gem->height()));
        break;
        //��
    case 2:
        animation->setEndValue(QRect(gem->geometry().x(), gem->geometry().y() + 42 * h, gem->width(), gem->height()));
        break;
        //��
    case 3:
        animation->setEndValue(QRect(gem->geometry().x() - 42 * h, gem->geometry().y(), gem->width(), gem->height()));
        break;
        //��
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

void Game::resetGem() {
    //��������
    //�����·���
}

void Game::buttonClicked() {//2021-12-21 ����ï buttonClickedԭ���ݸĳɽ�ѡ�е�������������rule�ж��Ƿ��ִ��
    //test
    if (gCounter == 0) {
        g1 = qobject_cast<Gem*>(sender());//���źŵķ�����ת����pushbutton����
        gCounter = 1;
    }
   else if (gCounter == 1) {
        g2 = qobject_cast<Gem*>(sender());
        int g1x = g1->x(), g1y = g1->y(), g2x = g2->x(), g2y = g2->y();
        int switchFlag=0;
        //����������鲻����һ�����ѡ����ͬһ������
        if (abs(g1->y() - g2->y()) + abs(g1->x() - g2->x()) > 1||abs( g1->y() - g2->y()) + abs(g1->x() - g2->x())==0)
            qDebug() << "cannot swap";
        //����������鿿��һ��
        else {
            //���»�
            if (g1->x() == g2->x()) {
                if (g1->y() > g2->y()) {
                    fallAnimation(g1, 1, 1);
                    fallAnimation(g2, 1, 2);
                    switchFlag = 1;
                }
                else {
                    fallAnimation(g1, 1, 2);
                    fallAnimation(g2, 1, 1);
                    switchFlag = 2;
                }
            }
            //���һ�
            else if (g1->y() == g2->y()) {
                if (g1->x() > g2->x()) {
                    fallAnimation(g1, 1, 3);
                    fallAnimation(g2, 1, 4);
                    switchFlag = 3;
                }
                else
                {
                    fallAnimation(g1, 1, 4);
                    fallAnimation(g2, 1, 3);
                    switchFlag = 4;
                }
            }
        }
        if (!rule->isCanSwap(g1y, g1x, g2y, g2x)) {//���ܽ����Ļ��ض���
            qDebug() << "swap"<<g1->type()<<","<<g2->type()<<" invalid";
        }
        else
        {
            rule->swap(g1->y(), g1->x(), g2->y(), g2->x());
            qDebug() << "swap" << g1->type() << "," << g2->type() << "ok";
            resetGem();
        }
        gCounter = 0;
    }
}

