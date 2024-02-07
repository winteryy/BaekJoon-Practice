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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    vector<vector<int> > matrix(n, vector<int>(m));
    queue<pair<pair<int, int>, int> > q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j]==1) {
                q.push({{i, j}, 0});
                matrix[i][j] = 0;
            }
        } 
    }

    int result = 0;

    while(!q.empty()) {
        pair<int, int> cur = q.front().first;
        int curDay = q.front().second;
        q.pop();

        if(matrix[cur.first][cur.second]==1) continue;
        matrix[cur.first][cur.second] = 1;
        
        if(curDay>result) {
            result = curDay;
        }

        for(int k=0; k<4; k++) {
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];
            if(isValid(ny, nx) && matrix[ny][nx]==0) {
                q.push({{ny, nx}, curDay+1});
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 0) {
                cout << "-1";
                return 0;
            }
        }
    }
    
    cout << result;
}