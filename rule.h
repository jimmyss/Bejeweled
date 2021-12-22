#pragma once
#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <vector>
#include<qdebug.h>
using namespace std;

class Bejewled {
private:
    int row = 10;
    int col = 10;
    vector<vector<int>> graph;

    // search the same item in four directions, return the number
    int searchLeft(int i, int j);
    int searchRight(int i, int j);
    int searchUp(int i, int j);
    int searchDown(int i, int j);

    bool isCanSwap(int i, int j, int a, int b);
    void adjust();
public:
    Bejewled();
    ~Bejewled() { }
    void setGraph(int x, int y, int type);
    void dispaly();
    void swap(int i, int j, int a, int b);
    bool isOver();

    // for the total serach, do judgement work
    // can add additional functions
    // i,j are index of the matrix
    int search(int i, int j);
};

#endif // !RULE_H