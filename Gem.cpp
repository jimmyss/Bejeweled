#include "Gem.h"
#include <QDebug>

Gem::Gem(int type, int len, int x, int y, QWidget* parent, int offset) : QPushButton(parent), _type(type), _x(x), _y(y)
{
    initGemPath();
    setGeometry(len * x + 20, len * y + 100, len, len);
    setIcon(QIcon(gemPath[type]));
    setIconSize(QSize(len, len));
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
}

void Gem::bomb() {
    delete this;
}