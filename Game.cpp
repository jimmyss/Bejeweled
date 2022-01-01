#include "Game.h"

Game::Game(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    runtime = new QTimer(this);
    rule = new Bejewled();
    connect(runtime, SIGNAL(timeout()), this, SLOT(update()));

    this->setAttribute(Qt::WA_DeleteOnClose);

    //���ñ���ͼƬ
    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground("pictures/style1/bg.jpg");
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
        "QPushButton{padding:6px;}";                          //���

    ui.pushButtonFinish->setStyleSheet(buttonStyle1);

    srand((int)time(0));
    bool flag = true;
    roundNumber = 0;
    fallMatrix = vector<vector<int>>(10, vector<int>(10, 0));
    generateMatrix = vector<vector<int>>(10, vector<int>(10, -1));
    deleteMatrix = vector<vector<int>>(10, vector<int>(10, 0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int rNum = rand() % 7;
            rule->setGraph(i, j, rNum);
            rule->adjust(fallMatrix, generateMatrix, flag);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            gems[i][j] = new Gem(rule->getGraph(i, j), 42, j, i, this);
            connect(gems[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));//�ź�0
        }
    }
    rule->clearBomb();
    fallMatrix = vector<vector<int>>(10, vector<int>(10, 0));
    generateMatrix = vector<vector<int>>(10, vector<int>(10, -1));
    deleteMatrix = vector<vector<int>>(10, vector<int>(10, 0));
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

void Game::setGems(int x, int y, int type) {
    gems[x][y] = new Gem(rule->getGraph(x, y), 42, y, x, this);
}

QPropertyAnimation* Game::fallAnimation(Gem* gem, int h, int flag) {
    QPropertyAnimation* animation = new QPropertyAnimation(gem, "geometry", this);
    animation->setDuration(500);
    animation->setStartValue(gem->geometry());
    switch (flag)
    {
        //��
    case 1:
        animation->setEndValue(QRect(gem->geometry().x(), gem->geometry().y() - 42 * h, gem->width(), gem->height()));
        gem->setGeometry(gem->geometry().x(), gem->geometry().y() - 42 * h, gem->width(), gem->height());
        break;
        //��
    case 2:
        animation->setEndValue(QRect(gem->geometry().x(), gem->geometry().y() + 42 * h, gem->width(), gem->height()));
        gem->setGeometry(gem->geometry().x(), gem->geometry().y() + 42 * h, gem->width(), gem->height());
        break;
        //��
    case 3:
        animation->setEndValue(QRect(gem->geometry().x() - 42 * h, gem->geometry().y(), gem->width(), gem->height()));
        gem->setGeometry(gem->geometry().x() - 42 * h, gem->geometry().y(), gem->width(), gem->height());
        break;
        //��
    case 4:
        animation->setEndValue(QRect(gem->geometry().x() + 42 * h, gem->geometry().y(), gem->width(), gem->height()));
        gem->setGeometry(gem->geometry().x() + 42 * h, gem->geometry().y(), gem->width(), gem->height());
        break;
    default:
        break;
    }
    animation->setEasingCurve(QEasingCurve::InQuad);
    //animation->start();
    /*QTimer::singleShot(1000, this, [=]() {
        delete animation;
        });*/
    return animation;
}

void Game::switchBlock() {
    Gem* temp;
    temp = gems[g1y][g1x];
    gems[g1y][g1x] = gems[g2y][g2x];
    gems[g2y][g2x] = temp;
    gems[g1y][g1x]->setX(g1x);
    gems[g1y][g1x]->setY(g1y);
    gems[g2y][g2x]->setX(g2x);
    gems[g2y][g2x]->setY(g2y);

    rule->swap(g1y, g1x, g2y, g2x);
}

QParallelAnimationGroup* Game::clearBlock() {
    QParallelAnimationGroup* bomb;
    bomb = rule->showBomb(gems, deleteMatrix,roundNumber);
    rule->fallGem(fallMatrix, generateMatrix);
    return bomb;
}

QParallelAnimationGroup* Game::fallBlock() {
    QParallelAnimationGroup* fall = new QParallelAnimationGroup;
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            if (fallMatrix[i][j] != 0 && deleteMatrix[i][j] != 1) {
                QPropertyAnimation* ani = fallAnimation(gems[i][j], fallMatrix[i][j], 2);
                fall->addAnimation(ani);
                gems[i + fallMatrix[i][j]][j] = gems[i][j];
                gems[i][j] = NULL;
                gems[i + fallMatrix[i][j]][j]->setX(j);
                gems[i + fallMatrix[i][j]][j]->setY(i + fallMatrix[i][j]);
            }
        }
    }
    return fall;
}
void Game::generatGems() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (generateMatrix[i][j] != -1) {
                gems[i][j] = new Gem(generateMatrix[i][j], 42, j, i, this);
                connect(gems[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));//�ź�0
            }
        }
    }
}


void Game::resetBlock() {
    fallMatrix = vector<vector<int>>(10, vector<int>(10, 0));
    generateMatrix = vector<vector<int>>(10, vector<int>(10, -1));
    deleteMatrix = vector<vector<int>>(10, vector<int>(10, 0));
}

void Game::buttonClicked() {//2021-12-21 ����ï buttonClickedԭ���ݸĳɽ�ѡ�е�������������rule�ж��Ƿ��ִ��
    clicksound();
    QSequentialAnimationGroup* seqAniGroup1 = new QSequentialAnimationGroup;
    QSequentialAnimationGroup* seqAniGroup2 = new QSequentialAnimationGroup;
    QPropertyAnimation* ani1 = new QPropertyAnimation;
    QPropertyAnimation* ani2 = new QPropertyAnimation;
    QPropertyAnimation* ani3 = new QPropertyAnimation;
    QPropertyAnimation* ani4 = new QPropertyAnimation;

    if (gCounter == 0) {
        g1 = qobject_cast<Gem*>(sender());//���źŵķ�����ת����pushbutton����
        
        gCounter = 1;
    }
    else if (gCounter == 1) {
        g2 = qobject_cast<Gem*>(sender());
        g1x = g1->x(), g1y = g1->y(), g2x = g2->x(), g2y = g2->y();
        int switchFlag = 0;
        //����������鲻����һ�����ѡ����ͬһ������
        if (abs(g1->y() - g2->y()) + abs(g1->x() - g2->x()) > 1 || abs(g1->y() - g2->y()) + abs(g1->x() - g2->x()) == 0)
            qDebug() << "cannot swap";
        //����������鿿��һ��
        else {
            //���»�
            if (g1->x() == g2->x()) {
                if (g1->y() > g2->y()) {
                    ani1 = fallAnimation(g1, 1, 1);
                    ani2 = fallAnimation(g2, 1, 2);
                    switchFlag = 1;
                }
                else {
                    ani1 = fallAnimation(g1, 1, 2);
                    ani2 = fallAnimation(g2, 1, 1);
                    switchFlag = 2;
                }
            }
            //���һ�
            else if (g1->y() == g2->y()) {
                if (g1->x() > g2->x()) {
                    ani1 = fallAnimation(g1, 1, 3);
                    ani2 = fallAnimation(g2, 1, 4);
                    switchFlag = 3;
                }
                else
                {
                    ani1 = fallAnimation(g1, 1, 4);
                    ani2 = fallAnimation(g2, 1, 3);
                    switchFlag = 4;
                }
            }
            seqAniGroup1->addAnimation(ani1);
            seqAniGroup2->addAnimation(ani2);
        }
        if (!rule->isCanSwap(g1y, g1x, g2y, g2x)) {//���ܽ����Ļ��ض���
            qDebug() << "swap" << g1->type() << "," << g2->type() << " invalid";
            switch (switchFlag)
            {
                //��
            case 1:
                ani3 = fallAnimation(g1, 1, 2);
                ani4 = fallAnimation(g2, 1, 1);
                break;
                //��
            case 2:
                ani3 = fallAnimation(g1, 1, 1);
                ani4 = fallAnimation(g2, 1, 2);
                break;
                //��
            case 3:
                ani3 = fallAnimation(g1, 1, 4);
                ani4 = fallAnimation(g2, 1, 3);
                break;
                //��
            case 4:
                ani3 = fallAnimation(g1, 1, 3);
                ani4 = fallAnimation(g2, 1, 4);
                break;
            default:
                break;
            }
            seqAniGroup1->addPause(100);
            seqAniGroup2->addPause(100);
            seqAniGroup1->addAnimation(ani3);
            seqAniGroup2->addAnimation(ani4);
            seqAniGroup1->start();
            seqAniGroup2->start();
        }
        else
        {
            seqAniGroup1->start();
            seqAniGroup2->start();
            endFlag = false;
            switchBlock();//�Ƚ�����������
            check = false;
            
                QParallelAnimationGroup* bombAni = clearBlock();//ִ�������������
                connect(bombAni, &QParallelAnimationGroup::finished, [=] {
                    explodesound();
                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 10; j++) {
                            if (deleteMatrix[i][j] == 1) {
                                endFlag = false;
                                gems[i][j]->deleteBlock();
                                gems[i][j] = NULL;
                            }
                        }
                    }
                    QParallelAnimationGroup* fallAni = fallBlock();//ִ�з����������
                    connect(fallAni, &QParallelAnimationGroup::finished, [=] {
                        generatGems();
                        resetBlock();//�������������ֵ
                        rule->check(endFlag);
                        if (!endFlag) {
                            QParallelAnimationGroup* bombAni = clearBlock();//ִ�������������
                            connect(bombAni, &QParallelAnimationGroup::finished, [=] {
                                for (int i = 0; i < 10; i++) {
                                    for (int j = 0; j < 10; j++) {
                                        if (deleteMatrix[i][j] == 1) {
                                            endFlag = false;
                                            gems[i][j]->deleteBlock();
                                            gems[i][j] = NULL;
                                        }
                                    }
                                }
                                QParallelAnimationGroup* fallAni = fallBlock();//ִ�з����������
                                connect(fallAni, &QParallelAnimationGroup::finished, [=] {
                                    generatGems();
                                    resetBlock();//�������������ֵ
                                    rule->check(endFlag);
                                    if (!endFlag) {
                                        QParallelAnimationGroup* bombAni = clearBlock();//ִ�������������
                                        connect(bombAni, &QParallelAnimationGroup::finished, [=] {
                                            for (int i = 0; i < 10; i++) {
                                                for (int j = 0; j < 10; j++) {
                                                    if (deleteMatrix[i][j] == 1) {
                                                        endFlag = false;
                                                        gems[i][j]->deleteBlock();
                                                        gems[i][j] = NULL;
                                                    }
                                                }
                                            }
                                            QParallelAnimationGroup* fallAni = fallBlock();//ִ�з����������
                                            connect(fallAni, &QParallelAnimationGroup::finished, [=] {
                                                generatGems();
                                                resetBlock();//�������������ֵ
                                                rule->check(endFlag);
                                                if (!endFlag) {
                                                    QParallelAnimationGroup* bombAni = clearBlock();//ִ�������������
                                                    connect(bombAni, &QParallelAnimationGroup::finished, [=] {
                                                        for (int i = 0; i < 10; i++) {
                                                            for (int j = 0; j < 10; j++) {
                                                                if (deleteMatrix[i][j] == 1) {
                                                                    endFlag = false;
                                                                    gems[i][j]->deleteBlock();
                                                                    gems[i][j] = NULL;
                                                                }
                                                            }
                                                        }
                                                        QParallelAnimationGroup* fallAni = fallBlock();//ִ�з����������
                                                        connect(fallAni, &QParallelAnimationGroup::finished, [=] {
                                                            generatGems();
                                                            resetBlock();//�������������ֵ
                                                            rule->check(endFlag);
                                                            if (!endFlag) {
                                                                QParallelAnimationGroup* bombAni = clearBlock();//ִ�������������
                                                                connect(bombAni, &QParallelAnimationGroup::finished, [=] {
                                                                    for (int i = 0; i < 10; i++) {
                                                                        for (int j = 0; j < 10; j++) {
                                                                            if (deleteMatrix[i][j] == 1) {
                                                                                endFlag = false;
                                                                                gems[i][j]->deleteBlock();
                                                                                gems[i][j] = NULL;
                                                                            }
                                                                        }
                                                                    }
                                                                    QParallelAnimationGroup* fallAni = fallBlock();//ִ�з����������
                                                                    connect(fallAni, &QParallelAnimationGroup::finished, [=] {
                                                                        generatGems();
                                                                        resetBlock();//�������������ֵ
                                                                        rule->check(endFlag);
                                                                        /*if (!endFlag) {

                                                                        }*/
                                                                        });
                                                                    fallAni->start();
                                                                    });
                                                                bombAni->start();
                                                            }
                                                            });
                                                        fallAni->start();
                                                        });
                                                    bombAni->start();
                                                }
                                                });
                                            fallAni->start();
                                            });
                                        bombAni->start();
                                    }
                                    });
                                fallAni->start();
                                });
                            bombAni->start();
                        }
                        });
                    fallAni->start();
                    });
                bombAni->start();
        }

        gCounter = 0;
    }
}

void Game::on_pushButtonFinish_clicked()
{
    QMessageBox message(QMessageBox::NoIcon, "Tip", "Back successfully ");
    qDebug() << "your score: " << roundNumber;
    message.exec();
    emit backSignal(roundNumber);
    //this->close();//����������
}
