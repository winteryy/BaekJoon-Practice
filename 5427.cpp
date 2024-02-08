#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<char> > matrix;
vector<vector<bool> > isVisited;
int w, h;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int t=0; t<T; t++) {
        cin >> w >> h;
        matrix = vector<vector<char> >(h+2, vector<char>(w+2, 'E'));
        isVisited = vector<vector<bool> >(h+2, vector<bool>(w+2, false));

        set<pair<int, int> > fireSet;
        queue<pair<pair<int, int>, int> > q;

        for(int i=1; i<=h; i++) {
            for(int j=1; j<=w; j++) {
                cin >> matrix[i][j];
                if(matrix[i][j]=='@') {
                    q.push({{i, j}, 0});
                    matrix[i][j]=='.';
                }else if(matrix[i][j]=='*') {
                    fireSet.insert({i, j});
                }
            }
        }

        int time = 0;

        while(!q.empty()) {
            pair<int, int> cur = q.front().first;
            int curTime = q.front().second;
            q.pop();

            if(time==curTime) {
                set<pair<int, int> > newSet;
                for(auto fire: fireSet) {
                    for(int i=0; i<4; i++) {
                        int ny = fire.first+dy[i];
                        int nx = fire.second+dx[i];
                        if(matrix[ny][nx]=='.') {
                            matrix[ny][nx] = '*';
                            newSet.insert({ny, nx});
                        }
                    }
                }
                fireSet = newSet;
                time++;
            }

            if(matrix[cur.first][cur.second]=='E') {
                cout << curTime << "\n";
                time = -1;
                break;
            }else if(isVisited[cur.first][cur.second]) {
                continue;
            }
            
            isVisited[cur.first][cur.second] = true;

            for(int i=0; i<4; i++) {
                int ny = cur.first+dy[i];
                int nx = cur.second+dx[i];

                if(matrix[ny][nx]=='.' || matrix[ny][nx]=='E') {
                    q.push({{ny, nx}, curTime+1});
                }
            }
        }
        if(time != -1) {
            cout << "IMPOSSIBLE\n";
        }
    }

}