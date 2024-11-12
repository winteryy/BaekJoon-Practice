#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
char matrix[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<bool> > isVisited(n, vector<bool>(n, false));
    int rgbNum = 0, rbNum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!isVisited[i][j]) {
                stack<pair<int, int> > st;
                char c = matrix[i][j];
                rgbNum++;
                st.push({i, j});
                while(!st.empty()) {
                    auto cur = st.top();
                    st.pop();
                    if(isVisited[cur.first][cur.second]) continue;

                    isVisited[cur.first][cur.second] = true;

                    for(int k=0; k<4; k++) {
                        int nextY = cur.first+dy[k];
                        int nextX = cur.second+dx[k];

                        if(0<=nextY && n>nextY && 0<=nextX && n>nextX && !isVisited[nextY][nextX] && c==matrix[nextY][nextX]) {
                            st.push({nextY, nextX});
                        }
                    }
                }
            }
        }
    }

    isVisited = vector<vector<bool> >(n, vector<bool>(n, false));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!isVisited[i][j]) {
                stack<pair<int, int> > st;
                char c = matrix[i][j];
                rbNum++;
                st.push({i, j});
                while(!st.empty()) {
                    auto cur = st.top();
                    st.pop();
                    if(isVisited[cur.first][cur.second]) continue;

                    isVisited[cur.first][cur.second] = true;

                    for(int k=0; k<4; k++) {
                        int nextY = cur.first+dy[k];
                        int nextX = cur.second+dx[k];

                        if(0<=nextY && n>nextY && 0<=nextX && n>nextX && !isVisited[nextY][nextX] &&
                         (c==matrix[nextY][nextX] || (c!='B' && matrix[nextY][nextX]!='B') ) ) {
                            st.push({nextY, nextX});
                        }
                    }
                }
            }
        }
    }

    cout << rgbNum << " " << rbNum;
}