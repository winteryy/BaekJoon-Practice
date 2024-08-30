#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;

int n, maxNum=0;
bool chessBoard[10][10];

bool leftDiagonal[19] = {false, };
bool rightDiagonal[19] = {false, };

vector<point> blankList;

void dfs(int cnt, int depth) {
    if(cnt+blankList.size()-depth <= maxNum) {
        return;
    }

    if(depth == blankList.size()) {
        maxNum = max(maxNum, cnt);
        return;
    }

    int y = blankList[depth].first;
    int x = blankList[depth].second;

    if(!leftDiagonal[y+x]
     && !rightDiagonal[x-y+n]) {
        leftDiagonal[y+x] = true;
        rightDiagonal[x-y+n] = true;

        dfs(cnt+1, depth+1);

        leftDiagonal[y+x] = false;
        rightDiagonal[x-y+n] = false;
    }

    dfs(cnt, depth+1);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> chessBoard[i][j];
            if(chessBoard[i][j]) blankList.push_back({i, j});        
        }
    }

    dfs(0, 0);

    cout << maxNum;

}