#include <iostream>
#include <stack>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

char matrix[600][600];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    pair<int, int> start;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j]=='I') {
                start = {i, j};
            }
        }
    }

    int cnt = 0;
    stack<pair<int, int> > st;
    st.push(start);

    while(!st.empty()) {
        auto cur = st.top();
        st.pop();

        if(matrix[cur.first][cur.second]=='X') {
            continue;
        } else if(matrix[cur.first][cur.second]=='P') {
            cnt++;
        }
        matrix[cur.first][cur.second] = 'X';

        for(int i=0; i<4; i++) {
            int newY = cur.first+dy[i];
            int newX = cur.second+dx[i];

            if(newY>=0 && newY<n && newX>=0 && newX<m && matrix[newY][newX]!='X') {
                st.push({newY, newX});
            }
        }
    }

    if(cnt==0) {
        cout << "TT";
    } else {
        cout << cnt;
    }
} 