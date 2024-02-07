#include <iostream>
#include <queue>

using namespace std;

int l;

int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int y, int x) {
    return y>=0 && y<l && x>=0 && x<l;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        pair<int, int> startP;
        pair<int, int> targetP;

        cin >> l >> startP.first >> startP.second >> targetP.first >> targetP.second;

        vector<vector<bool> > isVisited(l, vector<bool>(l, false));

        queue<pair<pair<int, int>, int> > q;
        q.push({startP, 0});

        while(!q.empty()) {
            pair<int, int> cur = q.front().first;
            int curCnt = q.front().second;
            q.pop();
            if(isVisited[cur.first][cur.second]) continue;
            isVisited[cur.first][cur.second] = true;

            if(cur==targetP) {
                cout << curCnt << "\n";
                break;
            }else {
                for(int j=0; j<8; j++) {
                    int ny = cur.first+dy[j];
                    int nx = cur.second+dx[j];
                    if(isValid(ny, nx) && !isVisited[ny][nx]) {
                        q.push({{ny, nx}, curCnt+1});
                    }
                }
            }
        }
    }

}