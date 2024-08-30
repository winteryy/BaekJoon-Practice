#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;

int n, maxNum=0;
int bishop[19];
bool chessBoard[19][19] = {false};

void dfs(int cnt, int depth) {
    if(cnt+(n*2-1)-depth <= maxNum) return;

    if(depth == n*2-1) {
        maxNum = max(maxNum, cnt);
        return;
    }
    
    for(int i=0; i<n*2-1; i++) {
        if(chessBoard[depth][i]) {
            bool flag = true;
            for(int j=0; j<depth; j++) {
                if(bishop[j]==i) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                bishop[depth] = i;
                dfs(cnt+1, depth+1);
            }
        }
    }

    bishop[depth] = -1;
    dfs(cnt, depth+1);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> chessBoard[i+j][j-i+n-1];    
        }
    }

    dfs(0, 0);
    cout << maxNum;
}
