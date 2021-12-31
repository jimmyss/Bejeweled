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
        if (left > 1 || up + down > 1) {
            switchGem(i, j, a, b);
            return true;
        }
        right = searchRight(a, b + 1);
        up = searchUp(a - 1, b);
        down = searchDown(a + 1, b);
        if (right > 1 || up + down > 1) {
            switchGem(i, j, a, b);
            return true;
        }
    }

    //a,b:lud i,j:rud
    if (i == a && j - b == 1) {
        left = searchLeft(a, b - 1);
        up = searchUp(a - 1, b);
        down = searchDown(a + 1, b);
        if (left > 1 || up + down > 1) {
            switchGem(i, j, a, b);
            return true;
        }
        right = searchRight(i, j + 1);
        up = searchUp(i - 1, j);
        down = searchDown(i + 1, j);
        if (right > 1 || up + down > 1) {
            switchGem(i, j, a, b);
            return true;
        }
    }

    // In the same colume

    //i,j:lru a,b:lrd
    if (j == b && a - i == 1) {
        left = searchLeft(i, j - 1);
        right = searchRight(i, j + 1);
        up = searchUp(i - 1, j);
        if (left + right > 1 || up > 1) {
            switchGem(i, j, a, b);
            return true;
        }
        left = searchLeft(a, b - 1);
        right = searchRight(a, b + 1);
        down = searchDown(a + 1, b);
        if (left + right > 1 || down > 1) {
            switchGem(i, j, a, b);
            return true;
        }
    }
    //a,b:lru i,j:lrd
    if (j == b && i - a == 1) {
        left = searchLeft(a, b - 1);
        right = searchRight(a, b + 1);
        up = searchUp(a - 1, b);
        if (left + right > 1 || up > 1) {
            switchGem(i, j, a, b);
            return true;
        }
        left = searchLeft(i, j - 1);
        right = searchRight(i, j + 1);
        down = searchDown(i + 1, j);
        if (left + right > 1 || down > 1) {
            switchGem(i, j, a, b);
            return true;
        }
    }

    switchGem(i, j, a, b);
    return false;
}

void Bejewled::switchGem(int i, int j, int a, int b) {
    int temp = graph[i][j];
    graph[i][j] = graph[a][b];
    graph[a][b] = temp;
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

QParallelAnimationGroup* Bejewled::showBomb(Gem* gems[10][10], vector<vector<int>>& delM, int& roundNumber) {
    QParallelAnimationGroup* bombGroup = new QParallelAnimationGroup;
    int size = bomb.size();
    roundNumber += size;
    int x, y;
    for (int k = 0; k < size; k++) {
        x = bomb.front().first;
        y = bomb.front().second;
        delM[x][y] = 1;
        QPropertyAnimation* bombAni = gems[x][y]->bomb();
        bombGroup->addAnimation(bombAni);
        bomb.pop();
    }
    return bombGroup;
}

// check, swap and ajust the graph
void Bejewled::swap(int i, int j, int a, int b) {
    // check is can swap
    //if (!isCanSwap(i, j, a, b)) return;
    // remove items after swap
    int tmp;
    int target;
    int left = 0, right = 0, up = 0, down = 0;
    pair<int, int> pos;

    switchGem(i, j, a, b);
    target = graph[i][j];
    up = searchUp(i - 1, j);
    down = searchDown(i + 1, j);
    if (up + down > 1) {
        graph[i][j] = -1;
        bomb.push(pos = make_pair(i, j));
        for (tmp = i - 1; tmp >= i - up; --tmp) {
            //if (graph[tmp][j] == target)
            graph[tmp][j] = -1;
            bomb.push(pos = make_pair(tmp, j));
        }
        for (tmp = i + 1; tmp <= i + down; ++tmp) {
            //if (graph[tmp][j] == target)
            graph[tmp][j] = -1;
            bomb.push(pos = make_pair(tmp, j));
        }
    }
    left = searchLeft(i, j - 1);
    right = searchRight(i, j + 1);
    if (left + right > 1) {
        graph[i][j] = -1;
        bomb.push(pos = make_pair(i, j));
        for (tmp = j - 1; tmp >= j - left; --tmp) {
            //if (graph[i][tmp] == target)
            graph[i][tmp] = -1;
            bomb.push(pos = make_pair(i, tmp));
        }
        for (tmp = j + 1; tmp <= j + right; ++tmp) {
            //if (graph[i][tmp] == target)
            graph[i][tmp] = -1;
            bomb.push(pos = make_pair(i, tmp));
        }
    }

    target = graph[a][b];
    up = searchUp(a - 1, b);
    down = searchDown(a + 1, b);
    if (up + down > 1) {
        graph[a][b] = -1;
        bomb.push(pos = make_pair(a, b));
        for (tmp = a - 1; tmp >= a - up; --tmp) {
            /*if (graph[tmp][b] == target)*/
            graph[tmp][b] = -1;
            bomb.push(pos = make_pair(tmp, b));
        }
        for (tmp = a + 1; tmp <= a + down; ++tmp) {
            /*if (graph[tmp][b] == target)*/
            graph[tmp][b] = -1;
            bomb.push(pos = make_pair(tmp, b));
        }
    }
    left = searchLeft(a, b - 1);
    right = searchRight(a, b + 1);
    if (left + right > 1) {
        graph[a][b] = -1;
        bomb.push(pos = make_pair(a, b));
        for (tmp = b - 1; tmp >= b - left; --tmp) {
            //if (graph[a][tmp] == target)
            graph[a][tmp] = -1;
            bomb.push(pos = make_pair(a, tmp));
        }
        for (tmp = b + 1; tmp <= b + right; ++tmp) {
            //if (graph[a][tmp] == target)
            graph[a][tmp] = -1;
            bomb.push(pos = make_pair(a, tmp));
        }
    }
    dispaly();
}

void Bejewled::fallGem(vector<vector<int>>& fallM, vector<vector<int>>& genM) {
    // fill the empty place and generate new items
    int height[10] = { 0 };
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; ++j) {
            if (graph[i][j] == -1) {
                height[j]++;
                for (int k = i; k > 0; --k) {
                    fallM[k - 1][j] = height[j];
                    graph[k][j] = graph[k - 1][j];
                }
                graph[0][j] = rand() % 7;
            }
        }
    }
    for (int h = 0; h < col; h++) {
        if (height[h] != 0) {
            for (int n = 0; n < height[h]; n++) {
                genM[n][h] = graph[n][h];
            }
        }
    }
}
//检查是否还有方块可以消除
void Bejewled::check(bool& c) {
    int tmp;
    int target;
    int left = 0, right = 0, up = 0, down = 0;
    pair<int, int> pos;
    c = true;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            target = graph[i][j];
            up = searchUp(i - 1, j);
            down = searchDown(i + 1, j);
            if (up + down > 1) {
                c = false;
                graph[i][j] = -1;
                bomb.push(pos = make_pair(i, j));
                for (tmp = i - 1; tmp >= i - up; --tmp) {
                    //if (graph[tmp][j] == target)
                    graph[tmp][j] = -1;
                    bomb.push(pos = make_pair(tmp, j));
                }
                for (tmp = i + 1; tmp <= i + down; ++tmp) {
                    //if (graph[tmp][j] == target)
                    graph[tmp][j] = -1;
                    bomb.push(pos = make_pair(tmp, j));
                }
            }
            left = searchLeft(i, j - 1);
            right = searchRight(i, j + 1);
            if (left + right > 1) {
                c = false;
                graph[i][j] = -1;
                bomb.push(pos = make_pair(i, j));
                for (tmp = j - 1; tmp >= j - left; --tmp) {
                    //if (graph[i][tmp] == target)
                    graph[i][tmp] = -1;
                    bomb.push(pos = make_pair(i, tmp));
                }
                for (tmp = j + 1; tmp <= j + right; ++tmp) {
                    //if (graph[i][tmp] == target)
                    graph[i][tmp] = -1;
                    bomb.push(pos = make_pair(i, tmp));
                }
            }
        }
    }
}


// ajust the graph to avoid left 3-item cases
void Bejewled::adjust(vector<vector<int>>& fallM, vector<vector<int>>& genM, bool& endFlag) {
    int tmp;
    int target;
    int left, right, up, down;
    pair<int, int> pos;
    bool isEnd = true;

    while (true)
    {
        for (int i = 0; i < row; ++i) {
            if (graph[i][0] == 7)break;
            for (int j = 0; j < col; ++j) {
                if (graph[i][j] == 7) break;
                target = graph[i][j];
                up = searchUp(i - 1, j);
                down = searchDown(i + 1, j);
                if (up + down > 1) {
                    isEnd = false;
                    endFlag = false;
                    bomb.push(pos = make_pair(i, j));
                    for (tmp = i - 1; tmp >= i - up; --tmp) {
                        graph[tmp][j] = -1;
                        bomb.push(pos = make_pair(tmp, j));
                    }
                    for (tmp = i + 1; tmp <= i + down; ++tmp) {
                        graph[tmp][j] = -1;
                        bomb.push(pos = make_pair(tmp, j));
                    }
                }
                left = searchLeft(i, j - 1);
                right = searchRight(i, j + 1);
                if (left + right > 1) {
                    isEnd = false;
                    endFlag = false;
                    bomb.push(pos = make_pair(i, j));
                    for (tmp = j - 1; tmp >= j - left; --tmp) {
                        graph[i][tmp] = -1;
                        bomb.push(pos = make_pair(i, tmp));
                    }
                    for (tmp = j + 1; tmp <= j + right; ++tmp) {
                        graph[i][tmp] = -1;
                        bomb.push(pos = make_pair(i, tmp));
                    }
                }
                int height[10] = { 0 };
                for (int m = 0; m < row; m++) {
                    for (int n = 0; n < col; n++) {
                        if (graph[m][n] == -1) {
                            height[n]++;
                            for (int p = m; p > 0; --p) {
                                fallM[p - 1][n] = height[n];
                                graph[p][n] = graph[p - 1][n];
                            }
                            graph[0][n] = rand() % 7;
                        }
                    }
                }
                for (int h = 0; h < col; h++) {
                    if (height[h] != 0) {
                        for (int n = 0; n < height[h]; n++) {
                            genM[n][h] = graph[n][h];
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

void Bejewled::clearBomb() {
    while (bomb.size() > 0) {
        bomb.pop();
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