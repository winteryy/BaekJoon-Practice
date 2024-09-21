#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    int n, m, k; 
    int y, x;
    for(int tc=0; tc<t; tc++) {
        cin >> m >> n >> k;
        vector<vector<bool> > matrix(n, vector<bool>(m, false));
        vector<pair<int, int> > cabbageList;

        for(int i=0; i<k; i++) {
            cin >> x >> y;
            matrix[y][x] = true;
            cabbageList.push_back({y, x});
        }

        int result = 0;
        for(auto p : cabbageList) {
            queue<pair<int, int> > q;
            q.push(p);
            bool firstWorm = false;

            while(!q.empty()) {
                auto fr = q.front();
                q.pop();
                if(matrix[fr.first][fr.second]) {
                    if(!firstWorm) {
                        result++;
                        firstWorm = true;
                    }
                    matrix[fr.first][fr.second] = false;
                    for(int j=0; j<4; j++) {
                        int nextY = fr.first+dy[j];
                        int nextX = fr.second+dx[j];

                        if(0<=nextX && m>nextX && 0<=nextY && n>nextY && matrix[nextY][nextX]) {
                            q.push({nextY, nextX});
                        }
                    }
                }
            }
        }
        cout << result << "\n";
    }
}