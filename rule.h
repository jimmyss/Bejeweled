#pragma once
#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <vector>
#include <queue>
#include <qdebug.h>
#include"Gem.h"
#include <QParallelAnimationGroup>
using namespace std;


class Bejewled {
private:
    int row = 10;
    int col = 10;
    vector<vector<int>> graph;
    queue<pair<int, int>> bomb;
    // search the same item in four directions, return the number
    int searchLeft(int i, int j);
    int searchRight(int i, int j);
    int searchUp(int i, int j);
    int searchDown(int i, int j);
public:
    Bejewled();
    ~Bejewled() { }
    void setGraph(int x, int y, int type);
    int getGraph(int x, int y);
    void adjust(vector<vector<int>>& fallM, vector<vector<int>>& genM, bool& endFlag);
    void check(bool& c);
    void fallGem(vector<vector<int>>& fallM, vector<vector<int>>& genM);
    void dispaly();
    QParallelAnimationGroup* showBomb(Gem* gems[10][10], vector<vector<int>>& delM);
    bool isCanSwap(int i, int j, int a, int b);
    void switchGem(int i, int j, int a, int b);
    void clearBomb();
    void swap(int i, int j, int a, int b);
    bool isOver();

    // for the total serach, do judgement work
    // can add additional functions
    // i,j are index of the matrix
    int search(int i, int j);
};

#endif // !RULE_H