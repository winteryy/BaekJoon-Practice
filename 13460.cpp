#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> point;
typedef pair<bool, point> ball_result;

int n, m;
int minDepth = 11;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ball_result moveBall(vector<vector<char> >& board, point p, int dir, bool isRed) {
    int curY = p.first;
    int curX = p.second;

    while(board[curY+dy[dir]][curX+dx[dir]] == '.') {
        curY += dy[dir];
        curX += dx[dir];
    }

    board[p.first][p.second] = '.';
    if(board[curY+dy[dir]][curX+dx[dir]] == 'O') {
        return {true, {curY+dy[dir], curX+dx[dir]}};
    } else {
        board[curY][curX] = isRed ? 'R' : 'B';
        return {false, {curY, curX}};
    }
}

void solve(vector<vector<char> > board, point blue, point red, int depth) {
    if(depth>=minDepth) return;

    for(int i=0; i<4; i++) {
        vector<vector<char> > newBoard(board);
        
        ball_result redResult, blueResult;
        if(
            (i==0 && blue.second>red.second) ||
            (i==1 && blue.first>red.first) ||
            (i==2 && blue.second<red.second) ||
            (i==3 && blue.first<red.first)
        ) {
            blueResult = moveBall(newBoard, blue, i, false);
            redResult = moveBall(newBoard, red, i, true);
        } else {
            redResult = moveBall(newBoard, red, i, true);
            blueResult = moveBall(newBoard, blue, i, false);            
        }

        if(blueResult.first) continue;;
        if(redResult.first) {
            minDepth = min(minDepth, depth);
            return;
        }
        if(blueResult.second == blue && redResult.second == red) continue;
        if(depth < 10) {
            solve(newBoard, blueResult.second, redResult.second, depth+1);
        } 
    }
}

int main() {
    cin >> n >> m;

    vector<vector<char> > board = vector<vector<char> >(n, vector<char>(m));
    point red, blue;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                red = {i, j};
            } else if(board[i][j] == 'B') {
                blue = {i, j};
            }
        }
    }

    solve(board, blue, red, 1);

    cout << (minDepth==11?-1:minDepth);
}