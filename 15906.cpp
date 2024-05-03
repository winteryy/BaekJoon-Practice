#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, t, targetY, targetX;
    cin >> n >> t >> targetY >> targetX;
    targetY--;
    targetX--;

    vector<vector<bool> > grid(n, vector<bool>(n));
    vector<vector<vector<int> > > warpDist(n, vector<vector<int> >(n, {INF, INF, INF, INF})); //left, up, right, down
    vector<pair<int, int> >  warpPos;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char c;
            cin >> c;
            if(c=='#') {
                warpPos.push_back({i, j});
            }
        }
    }

    for(auto pos: warpPos) {
        for(int i=0; i<4; i++) {
            int newY = pos.first;
            int newX = pos.second;
            int dist = 0;
            while(true) {
                newY += dy[i];
                newX += dx[i];
                dist++;

                if(!(newY>=0 && newY<n && newX>=0 && newX<n)) {
                    break;
                }else if(warpDist[newY][newX][i]>dist) {
                    warpDist[newY][newX][i] = dist;
                }else {
                    break;
                }
            }
        }
    }

    vector<vector<pair<int, int> > > isVisited = vector<vector<pair<int, int> > >(n, vector<pair<int, int> >(n, {INF, INF}));
    queue<pair<pair<int, int>, pair<int, int> > > q; //{{time, form}, {y, x}}
    q.push({{0, 0}, {0, 0}});

    while(!q.empty()) {
        int curTime = q.front().first.first;
        int curForm = q.front().first.second;
        pair<int, int> curPos = q.front().second;
        q.pop();

        if(curForm==0 && curTime>=isVisited[curPos.first][curPos.second].first) {
            continue;
        }else if(curForm==1 && curTime>=isVisited[curPos.first][curPos.second].second) {
            continue;
        }

        if(curForm==0) {
            isVisited[curPos.first][curPos.second].first = curTime;
        }else {
            isVisited[curPos.first][curPos.second].second = curTime;
        }

        if(curPos.first==targetY && curPos.second==targetX) {
            continue;
        }

        for(int i=0; i<4; i++) {
            int newY = curPos.first+dy[i];
            int newX = curPos.second+dx[i];

            if(newY>=0 && newY<n && newX>=0 && newX<n && isVisited[newY][newX].first>curTime+1) {
                q.push({{curTime+1, 0},{newY, newX}});
            }
        }

        for(int i=0; i<4; i++) {
            int newTime = curTime + (curForm==0?t+1:1);
            int newY = curPos.first;
            int newX = curPos.second;
            int dist = warpDist[curPos.first][curPos.second][i];
            if(dist==INF) continue;

            switch(i) {
                case 0: newX-=dist; break;
                case 1: newY-=dist; break;
                case 2: newX+=dist; break;
                case 3: newY+=dist; break;
            }

            if(isVisited[newY][newX].second>newTime) {
                q.push({{newTime, 1}, {newY, newX}});
            }   
        }
    }

    cout << min(isVisited[targetY][targetX].first, isVisited[targetY][targetX].second);
}