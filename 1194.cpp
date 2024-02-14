#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
vector<vector<char> > matrix;
vector<vector<vector<bool> > > isVisited;

bool isValid(int y, int x) {
    return (y>=0 && y<n && x>=0 && x<m); 
}

bool isUpperCase(char c) {
    return c>='A' && c<'G';
}

bool isLowerCase(char c) {
    return c>='a' && c<'g';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    matrix = vector<vector<char> > (n, vector<char>(m));
    isVisited = vector<vector<vector<bool> > > (n, vector<vector<bool> >(m, vector<bool>(1<<6, false)));

    pair<int, int> start;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j]=='0') {
                start = {i, j};
            }
        }
    }

    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push({start, {0, 0}});

    while(!q.empty()) {
        pair<int, int> curP = q.front().first;
        pair<int, int> curInfo = q.front().second;
        q.pop();

        if(isVisited[curP.first][curP.second][curInfo.second]) continue;
        if(matrix[curP.first][curP.second]=='1') {
            cout << curInfo.first;
            return 0;
        }

        isVisited[curP.first][curP.second][curInfo.second] = true;

        for(int i=0; i<4; i++) {
            int ny = curP.first+dy[i];
            int nx = curP.second+dx[i];
            if(isValid(ny, nx)) {
                if(isUpperCase(matrix[ny][nx])) {
                    if((curInfo.second&1 << matrix[ny][nx]-'A') && !isVisited[ny][nx][curInfo.second]) {
                        q.push({{ny, nx}, {curInfo.first+1, curInfo.second}});
                    }
                }else if(isLowerCase(matrix[ny][nx])) {
                    int nMask = curInfo.second | 1<<matrix[ny][nx]-'a';
                    if(!isVisited[ny][nx][nMask]) {
                        q.push({{ny, nx}, {curInfo.first+1, nMask}});
                    }
                }else if(matrix[ny][nx]!='#' && !isVisited[ny][nx][curInfo.second]) {
                    q.push({{ny, nx}, {curInfo.first+1, curInfo.second}});
                }
            }
        }
    }
    

    cout << "-1";
}