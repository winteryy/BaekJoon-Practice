#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

vector<vector<int> > matrix(500, vector<int>(500, 0));
vector<vector<bool> > isVisited(500, vector<bool>(500, false));
int maxSum = 0;
int n, m;
int selectedNum = 0;
int selectedSum = 0;

bool isValid(int y, int x) {
    return y>=0 && y<n && x>=0 && x<m;
} 

void dfs(int y, int x) {
    selectedNum++;
    selectedSum += matrix[y][x];
    isVisited[y][x] = true;

    if(selectedNum<4) {
        for(int i=0; i<4; i++) {
            int newY = y+dy[i];
            int newX = x+dx[i];
            if(isValid(newY, newX) && !isVisited[newY][newX]) {
                dfs(newY, newX);
            }
        }
    } else {
        maxSum = max(maxSum, selectedSum);
    }

    selectedNum--;
    selectedSum -= matrix[y][x];
    isVisited[y][x] = false;
}

void checkAdj(int y, int x) {
    int sum = matrix[y][x];
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int newY = y+dy[i];
        int newX = x+dx[i];
        if(isValid(newY, newX)) {
            cnt++;
            sum+=matrix[newY][newX];
        }
    }

    if(cnt==4) {
        for(int i=0; i<4; i++) {
            int newY = y+dy[i];
            int newX = x+dx[i];
            sum-=matrix[newY][newX];
            maxSum = max(maxSum, sum);
            sum+=matrix[newY][newX];
        }
    } else if(cnt==3) {
        maxSum = max(maxSum, sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dfs(i, j);
            checkAdj(i, j);
        }
    }

    cout << maxSum;
}