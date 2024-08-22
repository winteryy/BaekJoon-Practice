#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> point;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int t, h, w;
    cin >> t;

    char matrix[100][100];

    for(int tc=0; tc<t; tc++) {
        cin >> h >> w;

        vector<point> entranceList; // {y, x}

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> matrix[i][j];

                if((i==0||j==0||i==h-1||j==w-1)&&matrix[i][j]!='*') {
                    entranceList.push_back({i, j});
                }
            }
        }

        int keySave = 1; // 000..001(2) : 열쇠 없이 탐색하는 케이스
        string keyInput;
        cin >> keyInput;
        if(keyInput!="0") {
            for(auto c : keyInput) {
                keySave = keySave | 1<<(c-'a'+1);
            }
        }

        stack<pair<point, int> > st;
        for(auto p : entranceList) {
            st.push({p, keySave});
        }

        vector<vector<int> > isVisited = vector<vector<int> >(h, vector<int>(w, 0));
        int result = 0;
        while(!st.empty()) {
            point curPoint = st.top().first;
            int curKey = st.top().second;
            st.pop();

            if((isVisited[curPoint.first][curPoint.second] | curKey) != isVisited[curPoint.first][curPoint.second]) {
                char curChar = matrix[curPoint.first][curPoint.second];

                if(isupper(curChar) && (curKey & 1<<(curChar-'A'+1))==0) {
                    continue;
                } else if(matrix[curPoint.first][curPoint.second] == '$') {
                    result++;
                    matrix[curPoint.first][curPoint.second] = '.';
                } else if(islower(matrix[curPoint.first][curPoint.second])) {
                    curKey = curKey | 1<<(matrix[curPoint.first][curPoint.second]-'a'+1);
                }

                isVisited[curPoint.first][curPoint.second] = isVisited[curPoint.first][curPoint.second] | curKey;
                
                for(int i=0; i<4; i++) {
                    int targetY = curPoint.first+dy[i];
                    int targetX = curPoint.second+dx[i];
                    if(targetY>=0 && targetY<h && targetX>=0 && targetX<w) {
                        if(matrix[targetY][targetX]!='*' && ((isVisited[targetY][targetX] | curKey) != isVisited[targetY][targetX]) ) {
                            st.push({{targetY, targetX}, curKey});
                        } 
                    } else {
                        for(auto p: entranceList) {
                            if((isVisited[p.first][p.second] | curKey) != isVisited[p.first][p.second]) {
                                st.push({{p.first, p.second}, curKey});
                            }    
                        }
                    } 
                }

            }
        }

        cout << result << "\n";
    }
}