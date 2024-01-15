#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int matrix[1001][1001] = {0};
int accSum[1001][1001] = {0};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;

    for(int i=1; i<=n; i++) {
        cin >> s;
        for(int j=1; j<=m; j++) {
            if(s[j-1]=='1') {
                matrix[i][j] = 1;
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            accSum[i][j] = accSum[i-1][j]+accSum[i][j-1]-accSum[i-1][j-1]+matrix[i][j];
        }
    }

    int largestArea = 0;
    int largestLength = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            
            int endY=i+largestLength, endX=j+largestLength;

            if(matrix[i][j]==1) {
                while(endY<=n && endX<=m) {
                    int localArea = accSum[endY][endX]-accSum[i-1][endX]-accSum[endY][j-1]+accSum[i-1][j-1];
                    if(localArea==(endY-i+1)*(endX-j+1)) {
                        largestArea = max(largestArea, localArea);
                        largestLength = max(largestLength, endX-j+1);
                    }else {
                        break;
                    }
                    endX++;
                    endY++;
                }
            }
        }
    }

    cout << largestArea;
}