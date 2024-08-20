#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> point;

bool rowN[9][10] = {false, };
bool colN[9][10] = {false, };
bool blockN[9][10] = {false, };

int matrix[9][9];
vector<point> blankPointList;
bool endFlag = false;

int getBlockNum(int x, int y) {
    return (y/3)*3 + x/3; 
}

void sudoku(int depth) {
    if(endFlag) return;

    if(depth == blankPointList.size()) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << matrix[i][j];
            }
            cout << "\n";
        }
        endFlag = true;
        return;
    }

    int x = blankPointList[depth].second;
    int y = blankPointList[depth].first;

    int blockNum = getBlockNum(x, y);
    for(int i=1; i<=9; i++) {
        if(!rowN[y][i] && !colN[x][i] && !blockN[blockNum][i]) {
            rowN[y][i] = true;
            colN[x][i] = true;
            blockN[blockNum][i] = true;
            matrix[y][x] = i;

            sudoku(depth+1);

            matrix[y][x] = 0;
            rowN[y][i] = false;
            colN[x][i] = false;
            blockN[blockNum][i] = false;
        }
    }

}

int main() {

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            char c;
            cin >> c;
            matrix[i][j] = c-'0';
            if(matrix[i][j]==0) {
                blankPointList.push_back({i, j});                          
            } else {
                rowN[i][matrix[i][j]] = true;
                colN[j][matrix[i][j]] = true;
                blockN[getBlockNum(j, i)][matrix[i][j]] = true;
            }
        }
    }

    sudoku(0);
}