#include "Gem.h"
#include <QDebug>

Gem::Gem(int type, int len, int x, int y, QWidget* parent, int offset) : QPushButton(parent), _type(type), _x(x), _y(y)
{
    initGemPath();
    setGeometry(len * x + 20, len * y + 55, len, len);
    setIcon(QIcon(gemPath[type]));
    setIconSize(QSize(len, len));
    setFlat(true);
    show();


    connect(this, &Gem::clicked, [=](bool) {
        this->mouseClicked(this);
        });
}


void Gem::initGemPath() {
    gemPath[0] = "pictures/blk1.bmp";
    gemPath[1] = "pictures/blk2.bmp";
    gemPath[2] = "pictures/blk3.bmp";
    gemPath[3] = "pictures/blk4.bmp";
    gemPath[4] = "pictures/blk5.bmp";
    gemPath[5] = "pictures/blk6.bmp";
    gemPath[6] = "pictures/blk7.bmp";
    gemPath[7] = "pictures/blk1.bmp";

   /* gemPath[8] = "pictures/explode1.png";
    gemPath[9] = "pictures/explode2.png";
    gemPath[10] = "pictures/explode3.png";
    gemPath[11] = "pictures/explode4.png";
    gemPath[12] = "pictures/explode5.png";
    gemPath[13] = "pictures/explode6.png";
    gemPath[14] = "pictures/explode7.png";*/

}

void Gem::bomb() {
    /*QTimer* timer1 = new QTimer(this);
    timer1->setInterval(100);
    connect(timer1, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
     timer1->start();*/
    delete this;
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