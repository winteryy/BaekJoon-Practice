#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<pair<int, int> > minoState;
typedef vector<minoState> minoStateList;

minoStateList JMino { 
    { {0, 0}, {0, 1}, {1, 0}, {2, 0} },
    { {0, 0}, {0, 1}, {0, 2}, {1, 2} },
    { {0, 1}, {1, 1}, {2, 0}, {2, 1} },
    { {0, 0}, {1, 0}, {1, 1}, {1, 2} }
};

minoStateList LMino { 
    { {0, 0}, {0, 1}, {1, 1}, {2, 1} },
    { {0, 2}, {1, 0}, {1, 1}, {1, 2} },
    { {0, 0}, {1, 0}, {2, 0}, {2, 1} },
    { {0, 0}, {0, 1}, {0, 2}, {1, 0} }
};

minoStateList SMino { 
    { {0, 0}, {1, 0}, {1, 1}, {2, 1} },
    { {0, 1}, {0, 2}, {1, 0}, {1, 1} }
};

minoStateList ZMino { 
    { {0, 1}, {1, 0}, {1, 1}, {2, 0} },
    { {0, 0}, {0, 1}, {1, 1}, {1, 2} }
};

minoStateList TMino { 
    { {0, 0}, {1, 0}, {1, 1}, {2, 0} },
    { {0, 0}, {0, 1}, {0, 2}, {1, 1} },
    { {0, 1}, {1, 0}, {1, 1}, {2, 1} },
    { {0, 1}, {1, 0}, {1, 1}, {1, 2} }
};

minoStateList IMino { 
    { {0, 0}, {1, 0}, {2, 0}, {3, 0} },
    { {0, 0}, {0, 1}, {0, 2}, {0, 3} },
};

minoStateList OMino { 
    { {0, 0}, {0, 1}, {1, 0}, {1, 1} },
};

int dy[4] = {0, 1, 0};
int dx[4] = {1, 0, -1};
bool matrix[20][10];

int checkRemoveRowNum() {
    int result = 0;
    for(int i=0; i<20; i++) {
        bool flag = true;
        for(int j=0; j<10; j++) {
            if(!matrix[i][j]) {
                flag = false; 
                break;
            }
        }
        if(flag) result++;
    }

    return result;
}

int main() {
    char c;
    for(int i=0; i<20; i++) {
        for(int j=0; j<10; j++) {
            cin >> c;
            matrix[i][j] = c-'0';
        }
    }

    vector<minoStateList> minos {
        JMino, LMino, SMino, ZMino, TMino, IMino, OMino
    };

    int maxLine = 0;

    for(auto mino: minos) {
        for(auto minoState: mino) {
            vector<vector<bool> > isVisited(20, vector<bool>(10, false));
            queue<pair<int, int> > q;
            q.push({0, 0});

            while(!q.empty()) {
                int curY = q.front().first;
                int curX = q.front().second;
                q.pop();
                if(isVisited[curY][curX]) continue;
                isVisited[curY][curX] = true;

                bool flag = true;
                for(auto gap: minoState) {
                    int newY = curY+gap.first;
                    int newX = curX+gap.second;
                    if(!(newY<20 && newX<10 && !matrix[newY][newX])) {
                        flag = false;
                        break;
                    }
                }
                
                if(flag) {
                    bool gapFlag = false;
                    for(auto gap: minoState) {
                        int under = curY+gap.first+1;
                        if(under==20 || matrix[under][curX+gap.second]) {
                            gapFlag = true;
                            break;
                        }
                    }

                    if(gapFlag) {
                        for(auto gap: minoState) {
                            matrix[curY+gap.first][curX+gap.second] = true;
                        }
                        maxLine = max(maxLine, checkRemoveRowNum());
                        for(auto gap: minoState) {
                            matrix[curY+gap.first][curX+gap.second] = false;
                        }
                    }

                    for(int i=0; i<3; i++) {
                        int newY = curY+dy[i];
                        int newX = curX+dx[i];

                        if(newY<20 && newX>=0 && newX<10 && !isVisited[newY][newX]) {
                            q.push({newY, newX});
                        }
                    }
                }
            }
        }
    }

    cout << maxLine;
}