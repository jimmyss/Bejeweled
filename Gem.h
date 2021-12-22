#pragma once
#ifndef GEM_H
#define GEM_H

#include <QWidget>
#include <QMap>
#include <QPushButton>
#include <QPixmap>
#include <QMovie>
#include <QLabel>
#include<qicon.h>

class Gem : public QPushButton
{
    Q_OBJECT
public:
    explicit Gem(int _type, int len, int _x, int _y, QWidget* parent = nullptr, int offset = 0);
    Gem() {};//2021-12-21 杜世茂 可能出现“没有默认的构造函数”所以不了一个空构造函数
    int x() { return _x; }
    int y() { return _y; }
    void setY(int n) { _y = n; }
    int type() { return _type; }
    void bomb();

private:
    QMap<int, QString> gemPath;
    void initGemPath();
    int _type;
    int _x, _y;

    QMovie* gif;
    QLabel* gifLabel;

signals:
    void mouseClicked(Gem*);
};

#endif // GEM_H