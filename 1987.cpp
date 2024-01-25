#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<char> > matrix;
vector<bool> isVisited(26, false);
int w, h, maxNum=1;

bool isValid(pair<int, int>& p) {
    return p.first>=0 && p.second>=0 && p.first<h && p.second<w && isVisited[matrix[p.first][p.second]-'A']==false;
}

void DFS(pair<int, int> p, int curBlockNum) {
    bool flag = false;
    isVisited[matrix[p.first][p.second]-'A'] = true;

    for(int i=0; i<4; i++) {
        pair<int, int> nextP = make_pair(p.first+dy[i], p.second+dx[i]);
        if(isValid(nextP)) {
            flag = true;
            DFS(nextP, curBlockNum+1);
        }
    }
    if(!flag) {
        maxNum = max(maxNum, curBlockNum);
    }

    isVisited[matrix[p.first][p.second]-'A'] = false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> h >> w;
    
    matrix = vector<vector<char> >(h, vector<char>(w));

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> matrix[i][j];
        }
    }
    
    DFS(make_pair(0, 0), 1);
    cout << maxNum;

}