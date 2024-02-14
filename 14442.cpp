#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
vector<vector<bool> > matrix;
vector<vector<vector<int> > > isVisited;

bool isValid(int y, int x) {
    return (y>=0 && y<n && x>=0 && x<m); 
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> n >> m >> k;

    matrix = vector<vector<bool> > (n, vector<bool>(m, false));
    isVisited = vector<vector<vector<int> > > (n, vector<vector<int > >(m, vector<int>(k+1, -1)));
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            matrix[i][j] = s[j]-'0';
        }
    }

    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push({{0, 0}, {1, 0}});

    while(!q.empty()) {
        pair<int, int> curP = q.front().first;
        pair<int, int> curInfo = q.front().second;
        q.pop();
        if(isVisited[curP.first][curP.second][curInfo.second]!=-1 && isVisited[curP.first][curP.second][curInfo.second]<=curInfo.first) continue;

        if(curP.first==n-1 && curP.second==m-1) {
            cout << curInfo.first;
            return 0;
        }
        isVisited[curP.first][curP.second][curInfo.second] = curInfo.first;

        for(int i=0; i<4; i++) {
            int ny = curP.first + dy[i];
            int nx = curP.second + dx[i];

            if(isValid(ny, nx)) {
                if(matrix[ny][nx]) {
                    if(curInfo.second<k && (isVisited[ny][nx][curInfo.second+1]==-1 || isVisited[ny][nx][curInfo.second+1]>curInfo.first+1)) {
                        q.push({{ny, nx},{curInfo.first+1, curInfo.second+1}});
                    }
                }else {
                    if(isVisited[ny][nx][curInfo.second]==-1 || isVisited[ny][nx][curInfo.second]>curInfo.first+1) {
                        q.push({{ny, nx},{curInfo.first+1, curInfo.second}});
                    }
                }
            }
        }
    }

    cout << "-1";
}   