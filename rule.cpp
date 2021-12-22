#include"rule.h"

void Bejewled::setGraph(int x, int y, int type) {
    graph[x][y] = type;
}

int Bejewled::searchLeft(int i, int j) {
    if (j < 0 || graph[i][j] != graph[i][j + 1])
        return 0;
    else
        return searchLeft(i, j - 1) + 1;
}

int Bejewled::searchRight(int i, int j) {
    if (j >= col || graph[i][j] != graph[i][j - 1])
        return 0;
    else
        return searchRight(i, j + 1) + 1;
}


int Bejewled::searchUp(int i, int j) {
    if (i < 0 || graph[i][j] != graph[i + 1][j])
        return 0;
    else
        return searchUp(i - 1, j) + 1;
}

int Bejewled::searchDown(int i, int j) {
    if (i >= row || graph[i][j] != graph[i - 1][j])
        return 0;
    else
        return searchDown(i + 1, j) + 1;
}

int Bejewled::search(int i, int j) {
    qDebug() << "up:" << searchUp(i - 1, j) << endl;
    qDebug() << "down:" << searchDown(i + 1, j) << endl;
    qDebug() << "left:" << searchLeft(i, j - 1) << endl;
    qDebug() << "right:" << searchRight(i, j + 1) << endl;
    return 0;
}

// check is can swap, if true, swap the two items
bool Bejewled::isCanSwap(int i, int j, int a, int b) {
    // validation check, can be deleted
    if (i < 0 || i >= row || j < 0 || j >= col) return false;
    if (a < 0 || a >= row || b < 0 || b >= col) return false;

    // if same, don't need to swap
    if (graph[i][j] == graph[a][b]) return false;

    int tmp = graph[i][j];
    graph[i][j] = graph[a][b];
    graph[a][b] = tmp;

    // In the same row

    //i,j:lud a,b:rud
    if (i == a && b - j == 1) {
        if (searchLeft(i, j - 1) > 1 || searchUp(i - 1, j) + searchDown(i + 1, j) > 1)
            return true;
        if (searchRight(a, b + 1) > 1 || searchUp(a - 1, b) + searchDown(a + 1, b) > 1)
            return true;
    }

    //a,b:lud i,j:rud
    if (i == a && j - b == 1) {
        if (searchLeft(a, b - 1) > 1 || searchUp(a - 1, b) + searchDown(a + 1, b) > 1)
            return true;
        if (searchRight(i, j + 1) > 1 || searchUp(i - 1, j) + searchDown(i + 1, j) > 1)
            return true;
    }

    // In the same colume

    //i,j:lru a,b:lrd
    if (j == b && a - i == 1) {
        if (searchLeft(i, j - 1) + searchRight(i, j + 1) > 1 || searchUp(i - 1, j) > 1)
            return true;
        if (searchLeft(a, b - 1) + searchRight(a, b + 1) > 1 || searchDown(a + 1, b) > 1)
            return true;
    }
    //a,b:lru i,j:lrd
    if (j == b && i - a == 1) {
        if (searchLeft(a, b - 1) + searchRight(a, b + 1) > 1 || searchUp(a - 1, b) > 1)
            return true;
        if (searchLeft(i, j - 1) + searchRight(i, j + 1) > 1 || searchDown(i + 1, j) > 1)
            return true;
    }

    tmp = graph[i][j];
    graph[i][j] = graph[a][b];
    graph[a][b] = tmp;
    return false;
}

Bejewled::Bejewled() {
    graph = vector<vector<int>>(row, vector<int>(col, 0));
    /*for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            graph[i][j] = rand() % 3;
        }
    }*/
}

void Bejewled::dispaly() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            qDebug() << graph[i][j];
        }
        qDebug() << endl;
    }
}

// check, swap and ajust the graph
void Bejewled::swap(int i, int j, int a, int b) {
    // check is can swap
    if (!isCanSwap(i, j, a, b)) return;
    // remove items after swap
    int tmp;
    int target;

    target = graph[i][j];
    if (searchUp(i - 1, j) + searchDown(i + 1, j) > 1) {
        for (tmp = i; tmp >= 0; --tmp) {
            if (graph[tmp][j] == target)
                graph[tmp][j] = -1;
        }
        for (tmp = i; tmp < row; ++tmp) {
            if (graph[tmp][j] == target)
                graph[tmp][j] = -1;
        }
    }

    if (searchLeft(i, j - 1) + searchRight(i, j + 1) > 1) {
        for (tmp = j; tmp >= 0; --tmp) {
            if (graph[i][tmp] == target)
                graph[i][tmp] = -1;
        }
        for (tmp = j; tmp < col; ++tmp) {
            if (graph[i][tmp] == target)
                graph[i][tmp] = -1;
        }
    }

    target = graph[a][b];
    if (searchUp(a - 1, b) + searchDown(a + 1, b) > 1) {
        for (tmp = a; tmp >= 0; --tmp) {
            if (graph[tmp][b] == target)
                graph[tmp][b] = -1;
        }
        for (tmp = a; tmp < row; ++tmp) {
            if (graph[tmp][b] == target)
                graph[tmp][b] = -1;
        }
    }

    if (searchLeft(a, b - 1) + searchRight(a, b + 1) > 1) {
        for (tmp = b; tmp >= 0; --tmp) {
            if (graph[a][tmp] == target)
                graph[a][tmp] = -1;
        }
        for (tmp = b; tmp < col; ++tmp) {
            if (graph[a][tmp] == target)
                graph[a][tmp] = -1;
        }
    }

    this->dispaly();
    // fill the empty place and generate new items
    for (int i = row - 1; i >= 0; --i) {
        for (int j = 0; j < col; ++j) {
            if (graph[i][j] == -1) {
                for (int k = i; k > 0; --k) {
                    graph[k][j] = graph[k - 1][j];
                }
                graph[0][j] = rand() % 3;
            }
        }
    }

    adjust();
}


// ajust the graph to avoid left 3-item cases
void Bejewled::adjust() {
    int tmp;
    int target;
    bool isEnd = true;

    while (true)
    {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                target = graph[i][j];
                if (searchUp(i - 1, j) + searchDown(i + 1, j) > 1) {
                    isEnd = false;
                    for (tmp = i; tmp >= 0; --tmp) {
                        if (graph[tmp][j] == target)
                            graph[tmp][j] = -1;
                    }
                    for (tmp = i; tmp < row; ++tmp) {
                        if (graph[tmp][j] == target)
                            graph[tmp][j] = -1;
                    }
                }

                if (searchLeft(i, j - 1) + searchRight(i, j + 1) > 1) {
                    isEnd = false;
                    for (tmp = j; tmp >= 0; --tmp) {
                        if (graph[i][tmp] == target)
                            graph[i][tmp] = -1;
                    }
                    for (tmp = j; tmp < col; ++tmp) {
                        if (graph[i][tmp] == target)
                            graph[i][tmp] = -1;
                    }
                }
                for (int i = row - 1; i >= 0; --i) {
                    for (int j = 0; j < col; ++j) {
                        if (graph[i][j] == -1) {
                            for (int k = i; k > 0; --k) {
                                graph[k][j] = graph[k - 1][j];
                            }
                            graph[0][j] = rand() % 3;
                        }
                    }
                }
            }
        }
        if (!isEnd)
            isEnd = true;
        else break;

    }

}

bool Bejewled::isOver() {
    for (int i = 0; i < row - 1; ++i) {
        for (int j = 0; j < col - 1; ++j) {
            if (isCanSwap(i, j, i, j + 1) || isCanSwap(i, j, i + 1, j))
                return false;
        }
    }
    return true;
}