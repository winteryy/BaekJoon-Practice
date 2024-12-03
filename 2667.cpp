#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<bool> > matrix(n, vector<bool>(n, false));
    char input;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> input;
            if(input=='1') matrix[i][j] = true;
        }
    }

    vector<int> answer;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == true) {
                stack<pair<int, int> > st;
                st.push({i, j});
                int sum = 0;
                while(!st.empty()) {
                    int curY = st.top().first;
                    int curX = st.top().second;
                    st.pop();

                    if(!matrix[curY][curX]) continue;

                    sum++;
                    matrix[curY][curX] = false;

                    for(int k=0; k<4; k++) {
                        int nextY = curY + dy[k];
                        int nextX = curX + dx[k];

                        if(nextY>=0 && nextY<n && nextX>=0 && nextX<n && matrix[nextY][nextX]) {
                            st.push({nextY, nextX});
                        }
                    }
                }

                answer.push_back(sum);
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for(int ans: answer) {
        cout << ans << "\n";
    }
}