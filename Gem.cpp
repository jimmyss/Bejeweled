#include "Gem.h"
#include <QDebug>

Gem::Gem(int type, int len, int x, int y, QWidget* parent, int offset) : QPushButton(parent), _type(type), _x(x), _y(y)
{
    initGemPath();
    setGeometry(len * x + 20, len * y + 55, len, len);
   
    setIcon(QIcon(gemPath[type]));
    setIconSize(QSize(len, len));
    //setFlat(true);
    QPropertyAnimation* genAni = gen();
    show();
    genAni->start();

    connect(this, &Gem::clicked, [=](bool) {
        this->mouseClicked(this);
        setIcon(QIcon(gemPath[type+8]));
        });
}



void Gem::initGemPath() {
    gemPath[0] = "pictures/blk1.jpg";
    gemPath[1] = "pictures/blk2.jpg";
    gemPath[2] = "pictures/blk3.jpg";
    gemPath[3] = "pictures/blk4.jpg";
    gemPath[4] = "pictures/blk5.jpg";
    gemPath[5] = "pictures/blk6.jpg";
    gemPath[6] = "pictures/blk7.jpg";

    gemPath[8] = "pictures/1blk1.jpg";
    gemPath[9] = "pictures/1blk2.jpg";
    gemPath[10] = "pictures/1blk3.jpg";
    gemPath[11] = "pictures/1blk4.jpg";
    gemPath[12] = "pictures/1blk5.jpg";
    gemPath[13] = "pictures/1blk6.jpg";
    gemPath[14] = "pictures/1blk7.jpg";


}





QPropertyAnimation* Gem::bomb() {
    /*QTimer* timer1 = new QTimer(this);
    timer1->setInterval(100);
    connect(timer1, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
     timer1->start();*/
    QPropertyAnimation* bomb = new QPropertyAnimation;
    bomb->setDuration(1000);
    bomb->setStartValue(QRect(this->geometry().x(), this->geometry().y(), this->width(), this->height()));
    bomb->setEndValue(QRect(this->geometry().x() + 0.5 * this->width(), this->geometry().y() + 0.5 * this->height(), 0, 0));
    //delete this;
    return bomb;
}

void Gem::on_timer_timeout() {
    if (num != 15) {
        setIcon(QIcon(gemPath[num]));
        num++;
    }
    else {
        delete this;
    }
}
QPropertyAnimation* Gem::gen() {
    QPropertyAnimation* gen = new QPropertyAnimation;
    gen->setDuration(1000);
    gen->setStartValue(QRect(this->geometry().x() + 0.5 * this->width(), this->geometry().y() + 0.5 * this->height(), 0, 0));
    gen->setEndValue(QRect(this->geometry().x(), this->geometry().y(), this->width(), this->height()));
    return gen;
}