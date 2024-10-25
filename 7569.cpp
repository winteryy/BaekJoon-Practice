#include <bits/stdc++.h>

using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int m, n, h;

struct Point3d{
    int h, n, m;
};

bool isValid(int z, int y, int x) {
    return z>=0 && z<h && y>=0 && y<n && x>=0 && x<m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> h;

    vector<vector<vector<int> > > tomatoCube(h, vector<vector<int> >(n, vector<int>(m)));
    queue<pair<Point3d, int> > q;
    int remainTomato = 0;

    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                cin >> tomatoCube[i][j][k];
                if(tomatoCube[i][j][k]==0 || tomatoCube[i][j][k]==1) {
                    remainTomato++;
                }
                if(tomatoCube[i][j][k]==1) {
                    tomatoCube[i][j][k] = -1;
                    q.push({{i, j, k}, 0});
                }
            }
        }
    }

    int day = 0;

    while(!q.empty()) {
        auto p = q.front().first;
        int curDay = q.front().second;
        q.pop();
        if(tomatoCube[p.h][p.n][p.m]==1) continue;
        day = curDay;
        remainTomato--;
        tomatoCube[p.h][p.n][p.m] = 1;
        for(int i=0; i<6; i++) {
            int nextZ = p.h+dz[i];
            int nextY = p.n+dy[i];
            int nextX = p.m+dx[i];
            if(isValid(nextZ, nextY, nextX) && tomatoCube[nextZ][nextY][nextX]==0) {
                q.push({{nextZ, nextY, nextX}, curDay+1});
            }
        }
    }

    if(remainTomato==0) {
        cout << day;
    } else {
        cout << -1;
    }
}