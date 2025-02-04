#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool> > seats;
vector<vector<int> > dp;
int n, m, maxNum = 0;

int getOneNumFromBinary(int num) {
    int cnt = 0;
    while(num>0) {
        if(num&1) cnt++;
        num = num>>1;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    while(c--) {
        cin >> n >> m;
        seats = vector<vector<bool> >(n, vector<bool>(m));
        maxNum = 0;
        char seatInfo;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> seatInfo;
                seats[i][j] = (seatInfo=='.' ? true : false);
            }
        }

        dp = vector<vector<int> >(n, vector<int>(1<<m, -1));

        for(int i=0; i<(1<<m); i++) { // 1열 초기화
            int cnt = 0;
            for(int j=0; j<m; j++) {
                if(i&(1<<j)) { // j행에 앉는 경우
                    if(!seats[0][j]) { // 부숴진 좌석
                        cnt = -1;
                        break;
                    }
                    if(( j>0 && (i&(1<<(j-1))) ) || ( j<m-1 && (i&(1<<(j+1))) )) { // 좌우 확인
                        cnt = -1;
                        break;
                    }
                    cnt++;
                }
            }

            dp[0][i] = cnt;
        }
        
        for(int row=1; row<n; row++) { // 각 열 순회
            for(int i=0; i<(1<<m); i++) { // row열 배치
                bool isValid = true;

                for(int k=0; k<m; k++) {
                    if(i&(1<<k)) {
                        if(!seats[row][k]) { // 부서진 좌석 확인
                            isValid = false;
                            break;
                        }
                        if(( k>0 && (i&(1<<(k-1))) ) || ( k<m-1 && (i&(1<<(k+1))) )) { // 좌우인접 확인
                            isValid = false;
                            break;
                        }
                    }
                }
                if(!isValid) {
                    continue;
                }
                
                dp[row][i] = getOneNumFromBinary(i);
                int curNum = dp[row][i];

                for(int j=0; j<(1<<m); j++) { // row-1열 배치
                    if(dp[row-1][j]==-1) continue;

                    bool isValid = true;
                    for(int k=0; k<m; k++) {
                        if(i&(1<<k)) { // k번째 행에 앉는 경우
                            if(( k>0&&(j&(1<<(k-1))) ) || ( k<m-1 && (j&(1<<(k+1))) )) { // 대각선 확인
                                isValid = false;
                                break;
                            }
                        }
                    }

                    if(isValid) {
                        dp[row][i] = max(dp[row][i], dp[row-1][j]+curNum);
                    }
                }
            }
        }

        for(int i=0; i<(1<<m); i++) {
            maxNum = max(maxNum, dp[n-1][i]);
        }

        cout << maxNum << "\n";
    }
}