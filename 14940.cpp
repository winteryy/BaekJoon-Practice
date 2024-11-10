#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > matrix(n, vector<int>(m));
    vector<vector<int> > result(n, vector<int>(m, 0));
    pair<int, int> start;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j]==2) {
                start = {i, j};
            }
        }
    }

    queue<pair<pair<int, int>, int> > q;
    q.push({{start.first, start.second}, 0});

    while(!q.empty()) {
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if(result[curY][curX]!=0) continue;
        result[curY][curX] = dist;

        for(int i=0; i<4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            if(0<=nextY && n>nextY && 0<=nextX && m>nextX && matrix[nextY][nextX]==1 && result[nextY][nextX]==0) {
                q.push({{nextY, nextX}, dist+1});
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(result[i][j]==0 && matrix[i][j]==1) {
                cout << "-1" << " ";
            }
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}