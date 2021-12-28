#include"rule.h"

void Bejewled::setGraph(int x, int y, int type) {
    graph[x][y] = type;
}

int Bejewled::getGraph(int x, int y) {
    return graph[x][y];
}

int Bejewled::searchLeft(int i, int j) {
    if (j < 0 || graph[i][j] != graph[i][j + 1])
        return 0;
    else
        return searchLeft(i, j - 1) + 1;
    qDebug() << "";
}

int Bejewled::searchRight(int i, int j) {
    if (j >= col || graph[i][j] != graph[i][j - 1])
        return 0;
    else
        return searchRight(i, j + 1) + 1;
    qDebug() << "";
}


int Bejewled::searchUp(int i, int j) {
    if (i < 0 || graph[i][j] != graph[i + 1][j])
        return 0;
    else
        return searchUp(i - 1, j) + 1;
    qDebug() << "";
}

int Bejewled::searchDown(int i, int j) {
    if (i >= row || graph[i][j] != graph[i - 1][j])
        return 0;
    else
        return searchDown(i + 1, j) + 1;
    qDebug() << "";
}

int Bejewled::search(int i, int j) {
    qDebug() << "up:" << searchUp(i - 1, j);
    qDebug() << "down:" << searchDown(i + 1, j);
    qDebug() << "left:" << searchLeft(i, j - 1);
    qDebug() << "right:" << searchRight(i, j + 1);
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

    int left = 0, right = 0, up = 0, down = 0;
    // In the same row

    //i,j:lud a,b:rud
    if (i == a && b - j == 1) {
        left = searchLeft(i, j - 1);
        up = searchUp(i - 1, j);
        down = searchDown(i + 1, j);
        if (left > 1 || up + down > 1)
            return true;
        right = searchRight(a, b + 1);
        up = searchUp(a - 1, b);
        down = searchDown(a + 1, b);
        if ( right > 1 || up + down > 1)
            return true;
    }

    //a,b:lud i,j:rud
    if (i == a && j - b == 1) {
        left = searchLeft(a, b - 1);
        up = searchUp(a - 1, b);
        down = searchDown(a + 1, b);
        if (left > 1 || up + down > 1)
            return true;
        right = searchRight(i, j + 1);
        up = searchUp(i - 1, j);
        down = searchDown(i + 1, j);
        if (right > 1 || up + down > 1)
            return true;
    }

    // In the same colume

    //i,j:lru a,b:lrd
    if (j == b && a - i == 1) {
        left = searchLeft(i, j - 1);
        right = searchRight(i, j + 1);
        up = searchUp(i - 1, j);
        if (left + right > 1 || up > 1)
            return true;
        left = searchLeft(a, b - 1);
        right = searchRight(a, b + 1);
        down = searchDown(a + 1, b);
        if (left + right > 1 || down > 1)
            return true;
    }
    //a,b:lru i,j:lrd
    if (j == b && i - a == 1) {
        left = searchLeft(a, b - 1);
        right = searchRight(a, b + 1);
        up = searchUp(a - 1, b);
        if (left + right > 1 || up > 1)
            return true;
        left = searchLeft(i, j - 1);
        right = searchRight(i, j + 1);
        down = searchDown(i + 1, j);
        if (left + right > 1 || down > 1)
            return true;
    }

    tmp = graph[i][j];
    graph[i][j] = graph[a][b];
    graph[a][b] = tmp;
    return false;
}

Bejewled::Bejewled() {
    graph = vector<vector<int>>(row, vector<int>(col, 7));
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
        qDebug() << " ";
    }
}

// check, swap and ajust the graph
void Bejewled::swap(int i, int j, int a, int b) {
    // check is can swap
    if (!isCanSwap(i, j, a, b)) return;
    // remove items after swap
    int tmp;
    int target;
    int left = 0, right = 0, up = 0, down = 0;

    target = graph[i][j];
    up = searchUp(i - 1, j);
    down = searchDown(i + 1, j);
    if (up + down > 1) {
        for (tmp = i; tmp >= i-up; --tmp) {
            //if (graph[tmp][j] == target)
                graph[tmp][j] = -1;
        }
        for (tmp = i; tmp <= i+down; ++tmp) {
            //if (graph[tmp][j] == target)
                graph[tmp][j] = -1;
        }
    }
    left = searchLeft(i, j - 1);
    right = searchRight(i, j + 1);
    if (left + right > 1) {
        for (tmp = j; tmp >= j-left; --tmp) {
            //if (graph[i][tmp] == target)
                graph[i][tmp] = -1;
        }
        for (tmp = j; tmp <= j+right; ++tmp) {
            //if (graph[i][tmp] == target)
                graph[i][tmp] = -1;
        }
    }

    target = graph[a][b];
    up = searchUp(a - 1, b);
    down = searchDown(a + 1, b);
    if (up + down > 1) {
        for (tmp = a; tmp >= a-up; --tmp) {
            /*if (graph[tmp][b] == target)*/
                graph[tmp][b] = -1;
        }
        for (tmp = a; tmp <= a+down; ++tmp) {
            /*if (graph[tmp][b] == target)*/
                graph[tmp][b] = -1;
        }
    }
    left = searchLeft(a, b - 1);
    right = searchRight(a, b + 1);
    if (left + right > 1) {
        for (tmp = b; tmp >= b-left; --tmp) {
            //if (graph[a][tmp] == target)
                graph[a][tmp] = -1;
        }
        for (tmp = b; tmp <= b+right; ++tmp) {
            //if (graph[a][tmp] == target)
                graph[a][tmp] = -1;
        }
    }

    // fill the empty place and generate new items
    for (int i = row - 1; i >= 0; --i) {
        for (int j = 0; j < col; ++j) {
            if (graph[i][j] == -1) {
                for (int k = i; k > 0; --k) {
                    graph[k][j] = graph[k - 1][j];
                }
                graph[0][j] = rand() % 7;
            }
        }
    }
    adjust();
    this->dispaly();
}


// ajust the graph to avoid left 3-item cases
void Bejewled::adjust() {
    int tmp;
    int target;
    int left, right, up, down;
    bool isEnd = true;

    while (true)
    {
        for (int i = 0; i < row; ++i) {
            if (graph[i][0] == 7)break;
            for (int j = 0; j < col; ++j) {
                if (graph[i][j] == 7) break;
                target = graph[i][j];
                up = searchUp(i - 1, j);
                down=searchDown(i + 1, j);
                if (up + down > 1) {
                    isEnd = false;
                    for (tmp = i; tmp >= i-up; --tmp) {
                        if (graph[tmp][j] == target)
                            graph[tmp][j] = -1;
                    }
                    for (tmp = i; tmp <= i+down; ++tmp) {
                        if (graph[tmp][j] == target)
                            graph[tmp][j] = -1;
                    }
                }
                left = searchLeft(i, j - 1);
                right = searchRight(i, j + 1);
                if (left + right > 1) {
                    isEnd = false;
                    for (tmp = j; tmp >= j-left; --tmp) {
                        if (graph[i][tmp] == target)
                            graph[i][tmp] = -1;
                    }
                    for (tmp = j; tmp <= j+right; ++tmp) {
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
                            graph[0][j] = rand() % 7;
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