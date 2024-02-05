#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<bool> > seat(5, vector<bool>(5, false));
vector<vector<bool> > isVisited(5, vector<bool>(5, false));
int curS = 0;
int validCase = 0;

bool isValid(int y, int x) {
    return y>=0&&y<5&&x>=0&&x<5;
}

int DFS(int y, int x) {

    vector<vector<bool> > isVisitedCopy(isVisited);
    stack<pair<int, int> > st;
    st.push({y, x});


    int cnt = 0;
    while(!st.empty()) {
        pair<int, int> cur = st.top();
        st.pop();
        if(!isVisitedCopy[cur.first][cur.second]) continue;
        cnt++;
        isVisitedCopy[cur.first][cur.second] = false;

        for(int i=0; i<4; i++) {
            int nextY=cur.first+dy[i], nextX=cur.second+dx[i];
            if(isValid(nextY, nextX) && isVisitedCopy[nextY][nextX]) {
                st.push({nextY, nextX});
            }
        }
    }

    return cnt;
}

void solve(int prev, int depth) {
    if(depth == 7) {
        if(curS>3 && DFS(prev/5, prev%5)==7) {
            validCase++;
        }
        return;
    }


    for(int i=prev+1; i<25; i++) {   
        if(seat[i/5][i%5]) {
            curS++;
        }
        isVisited[i/5][i%5] = true;
        solve(i, depth+1);
        isVisited[i/5][i%5] = false;
        if(seat[i/5][i%5]) {
            curS--;
        }
    }
}

int main() {
    char c;

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> c;
            if(c=='S') seat[i][j]=true;
        }
    }

    solve(-1, 0);

    cout << validCase;

}