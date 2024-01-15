#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0 ,-1};
int dy[4] = {-1, 0, 1, 0};

int main( ){

    int height, width;
    cin >> height >> width;

    vector<vector<int> > matrix(height+2, vector<int>(width+2, 0)); //-1: 벽, 0: 공간, 1:치즈, 2:외부
    matrix[0] = vector<int>(width+2, -1);
    matrix[height+1] = vector<int>(width+2, -1);
    for(int i=1; i<=height; i++) {
        matrix[i][0] = -1;
        matrix[i][width+1] = -1;
    }

    for(int i=1; i<=height; i++) {
        for(int j=1; j<=width; j++) {
            cin >> matrix[i][j];
        }
    }

    int cnt = 0;

    while(1) {

        stack<pair<int, int> > s;
        s.push(make_pair(1,1));

        vector<vector<bool> > isVisited(height+2, vector<bool>(width+2, false));
        while(!s.empty()) {
            pair<int, int> now = s.top();
            s.pop();
            matrix[now.first][now.second] = 2;
            isVisited[now.first][now.second] = true;

            for(int i=0; i<4; i++) {
                // if(matrix[now.first+dy[i]][now.second+dx[i]] == 0 || 
                // (matrix[now.first+dy[i]][now.second+dx[i]] <= 2+cnt && matrix[now.first+dy[i]][now.second+dx[i]] > 1)) {
                //     s.push(make_pair(now.first+dy[i], now.second+dx[i]));
                // }]
                if(matrix[now.first+dy[i]][now.second+dx[i]] == 0 ||
                matrix[now.first+dy[i]][now.second+dx[i]] > 1 && !isVisited[now.first+dy[i]][now.second+dx[i]]) {
                    s.push(make_pair(now.first+dy[i], now.second+dx[i]));
                }
            }
 
        }

        bool remainCheese = false;

        for(int i=1; i<=height; i++) {
            for(int j=1; j<=width; j++) {
                if(matrix[i][j]==1) {
                    remainCheese = true;

                    int airSurface = 0;
                    for(int k=0; k<4; k++) {
                        if(matrix[i+dy[k]][j+dx[k]]<=2+cnt && matrix[i+dy[k]][j+dx[k]]>=2) {
                            airSurface++;
                        }
                    }

                    if(airSurface>=2) {
                        matrix[i][j] = cnt+3;
                    }
                }
            }
        }

        if(remainCheese==false) {
            cout << cnt;
            break;
        }

        cnt++;
    }



}