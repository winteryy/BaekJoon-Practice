#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    int n;
    cin >> n;

    vector<vector<int> > matrix(n+2, vector<int>(n+2, -1));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> matrix[i][j];
        }
    }

    int areaNum = 0;
    vector<int> areaVector;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            
            if(matrix[i][j]==1) {
                areaNum++;

                stack<pair<int, int> > st;
                st.push({i, j});
                int localArea = 0;

                while(!st.empty()) {
                    pair<int, int> point = st.top();
                    st.pop();
                    if(matrix[point.first][point.second]==1) {
                        localArea++;
                        matrix[point.first][point.second] = 0;
                    }
                    
                    for(int k=0; k<4; k++) {
                        if(matrix[point.first+dx[k]][point.second+dy[k]]==1) {
                            st.push({point.first+dx[k], point.second+dy[k]});
                        }
                    }

                }

                areaVector.push_back(localArea);
            }

        }
    }

    sort(areaVector.begin(), areaVector.end());
    cout << areaNum << "\n";
    for(int i=0; i<areaNum; i++) {
        cout << areaVector[i] << " ";
    }
}