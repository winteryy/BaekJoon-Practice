#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

class Dice{
public:
    int now, opposite, up, down, left, right;

    Dice() {
        now = 1;
        opposite = 6;
        up = 2;
        down = 5;
        left = 3;
        right = 4;
    }

    Dice(int now, int opposite, int up, int down, int left, int right) {
        this->now = now;
        this->opposite = opposite;
        this->up = up;
        this->down = down;
        this->left = left;
        this->right = right;
    }

    Dice rollUp() {
        return Dice(up, down, opposite, now, left, right);
    }

    Dice rollDown() {
        return Dice(down, up, now, opposite, left, right);
    }

    Dice rollLeft() {
        return Dice(left, right, up, down, opposite, now);
    }

    Dice rollRight() {
        return Dice(right, left, opposite, down, now, opposite);
    }
};

int main() {
    int map[18][6];

    pair<int, int> startPoints[3];

    for(int i=0; i<18; i++) {
        for(int j=0; j<6; j++) {
            cin >> map[i][j];
            if(map[i][j]==1) {
                startPoints[i/6] = {i, j};
            }
        }
    }

    vector<vector<bool> > isVisited(18, vector<bool>(6, false));

    for(int k=0; k<3; k++) {
        queue<pair<pair<int, int>, Dice> > q;
        q.push({startPoints[k], Dice()});
        vector<bool> isSelected(7, false);

        bool flag = true;

        while(!q.empty()) {
            Dice curDice = q.front().second;
            int curY = q.front().first.first;
            int curX = q.front().first.second;
            q.pop();

            if(isVisited[curY][curX]) continue;

            isVisited[curY][curX] = true;
            if(isSelected[curDice.now]) {
                flag = false;
                break;
            }else {
                isSelected[curDice.now] = true;

                for(int i=0; i<4; i++) {
                    int newY = curY+dy[i];
                    int newX = curX+dx[i];

                    if(newY>=0 && newY/6==k && newX>=0 && newX<6 && map[newY][newX]==1 && !isVisited[newY][newX]) {
                        Dice newDice;
                        switch (i) {
                            case 0: newDice=curDice.rollRight(); break;
                            case 1: newDice=curDice.rollDown(); break;
                            case 2: newDice=curDice.rollLeft(); break;
                            case 3: newDice=curDice.rollUp(); break;    
                        }
                        
                        q.push({{newY, newX}, newDice});
                    }
                }
            }
        }

        for(int i=1; i<=6; i++) {
            if(isSelected[i]==false) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "yes\n";
        }else {
            cout << "no\n";
        }
    }
}