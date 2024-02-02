#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
vector<vector<int> > matrix;
vector<vector<bool> > isVisited;

int getOceanNum(int y, int x) {
    int cnt = 0;
    for(int i=0; i<4; i++) {
        if(0<=y+dy[i]&&n>y+dy[i]&&0<=x+dx[i]&&m>x+dy[i]&&matrix[y+dy[i]][x+dx[i]]==0) {
            cnt++;
        }
    }
    return cnt;
}

vector<pair<int, int> > passYear() {
    vector<pair<int, int> > icebergs;
    vector<vector<int> > newMatrix(matrix);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j]!=0) {
                newMatrix[i][j] -= getOceanNum(i, j);

                if(newMatrix[i][j]<=0) {
                    newMatrix[i][j] = 0;
                }else {
                    icebergs.push_back({i, j});
                }
            }
        }
    }
    matrix = newMatrix;

    return icebergs;
}

void DFS(pair<int, int> ib) {
    stack<pair<int, int> > st;
    st.push(ib);

    while(!st.empty()) {
        pair<int, int> cur = st.top();
        st.pop();
        if(isVisited[cur.first][cur.second]) continue;

        int y = cur.first;
        int x = cur.second;

        isVisited[y][x] = true;
        for(int i=0; i<4; i++) {
            int newY = y+dy[i];
            int newX = x+dx[i];
            if(0<=newY&&n>newY&&0<=newX&&m>newX&&matrix[newY][newX]!=0&&!isVisited[newY][newX]) {
                st.push({newY, newX});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    matrix = vector<vector<int> >(n, vector<int>(m));

    vector<pair<int, int> > icebergs;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j]!=0) {
                icebergs.push_back({i, j});
            }
        }
    }

    int year = 0;

    while(true) {
        isVisited = vector<vector<bool> > (n, vector<bool>(m, false));
        if(icebergs.empty()) {
            year = 0;
            break;
        }

        int cnt = 0;
        for(auto ib: icebergs) {
            if(isVisited[ib.first][ib.second]) continue;
            cnt++;
            DFS(ib);
        }

        if(cnt>1) {
            break;
        }

        icebergs = passYear();
        year++;
    }


    cout << year;
}