#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int longestCandy(vector<vector<int> >& v) {
    int longestNum = 0;
    for(int i=1; i<v.size()-1; i++) {
        int prevXCandy = -1;
        int prevYCandy = -1;
        int nowNumX = 0;
        int nowNumY = 0; 
        for(int j=1; j<v.size()-1; j++) {
            if(prevXCandy==-1) {
                nowNumX = 1;
                nowNumY = 1;
                prevXCandy = v[i][j];
                prevYCandy = v[j][i];
            }else{
                
                if(prevXCandy==v[i][j]) {
                    nowNumX++;
                }else {
                    nowNumX = 1;
                    prevXCandy = v[i][j]; 
                }
                if(prevYCandy==v[j][i]) {
                    nowNumY++;
                }else {
                    nowNumY = 1;
                    prevYCandy = v[j][i]; 
                }
            }

            longestNum = max(longestNum, nowNumX);
            longestNum = max(longestNum, nowNumY);
        }
    }

    return longestNum;
}

int changeCandy(vector<vector<int> >& v, int x, int y) {
    int longestNum = 0;

    for(int i=0; i<4; i++) {
        if(v[y+dy[i]][x+dx[i]] != -1) {
            int temp = v[y+dy[i]][x+dx[i]];
            v[y+dy[i]][x+dx[i]] = v[y][x];
            v[y][x] = temp;
            longestNum = max(longestNum, longestCandy(v));

            v[y][x] = v[y+dy[i]][x+dx[i]];
            v[y+dy[i]][x+dx[i]] = temp;
        }
    }

    return longestNum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > matrix(n+2, vector<int>(n+2, -1));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            char c;
            cin >> c;
            matrix[i][j] = c-'A';
        }
    }

    int longestNum = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if((i+j)%2==0) {
                longestNum = max(longestNum, changeCandy(matrix, j, i));
            }
        }
    }

    cout << longestNum;
}