#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

bool isValid(int y, int x) {
    return y>=0&&y<n&&x>=0&&x<m;
}

int main() {
    cin >> n >> m;

    vector<vector<bool> > matrix(n, vector<bool>(m, false));
    vector<vector<bool> > isVisited(n, vector<bool>(m, false));

    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) {
            if(s[j]=='1') {
                matrix[i][j] = true;
            }
        }
    }

    queue<pair<pair<int, int>, int> > q;
    q.push({{0, 0}, 1});

    while(!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        if(isVisited[cur.first.first][cur.first.second]) continue;

        isVisited[cur.first.first][cur.first.second] = true;
        if(cur.first.first == n-1 && cur.first.second == m-1) {
            cout << cur.second;
            break;
        }

        for(int i=0; i<4; i++) {
            int nextY = cur.first.first+dy[i], nextX = cur.first.second+dx[i];

            if(isValid(nextY, nextX) && matrix[nextY][nextX] && !isVisited[nextY][nextX]) {
                q.push({{nextY, nextX}, cur.second+1});
            }
        }
    }

}