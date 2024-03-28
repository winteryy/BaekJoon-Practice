#include <iostream>
#include <vector>
#include <queue>
#define INF -987654321

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<bool> > maze(m, vector<bool> (n, false));
    vector<vector<int> > visited(m, vector<int> (n, INF));
    char c;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> c;
            maze[i][j] = c-'0';
        }
    }

    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({0, {0, 0}});
    visited[0][0] = 0;

    while(!pq.empty()) {
        int breakWall = pq.top().first;
        int curY = pq.top().second.first;
        int curX = pq.top().second.second;
        pq.pop();

        if(breakWall<visited[curY][curX]) continue;
        if(curY==m-1 && curX==n-1) {
            cout << -breakWall;
            break;
        }
        
        for(int i=0; i<4; i++) {
            int newX = curX+dx[i];
            int newY = curY+dy[i];
            if(newX>=0&&newX<n&&newY>=0&&newY<m) {
                if(maze[newY][newX]&&visited[newY][newX]<breakWall-1) {
                    visited[newY][newX] = breakWall-1;
                    pq.push({breakWall-1, {newY, newX}});
                }else if(!maze[newY][newX]&&visited[newY][newX]<breakWall) {
                    visited[newY][newX] = breakWall;
                    pq.push({breakWall, {newY, newX}});
                }
            }
        }
    }
}