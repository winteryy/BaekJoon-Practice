#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, w;
        cin >> n >> w;
        
        vector<vector<int> > enemyList(2, vector<int>(n)); //{{innerArr}, {outerArr}};
        for(int i=0; i<n; i++) {
            cin >> enemyList[0][i];
        }
        for(int i=0; i<n; i++) {
            cin >> enemyList[1][i];
        }

        if(n==1) {
            cout << (enemyList[0][0] + enemyList[1][0] <= w ? 1 : 2) << "\n";
            continue;
        }

        vector<pair<int, int> > initFlags; //{innerConnected, outerConnected};
        initFlags.push_back({false, false});
        if(enemyList[0][0]+enemyList[0][n-1]<=w) {
            initFlags.push_back({true, false});
        }
        if(enemyList[1][0]+enemyList[1][n-1]<=w) {
            initFlags.push_back({false, true});
        }        
        if(enemyList[0][0]+enemyList[0][n-1]<=w && enemyList[1][0]+enemyList[1][n-1]<=w) {
            initFlags.push_back({true, true});
        }   
        
        int minNum = INF;

        for(auto initCase: initFlags) {
            vector<vector<int> > dp(3, vector<int>(n, INF));
            dp[0][0] = initCase.second ? INF : 1;
            dp[1][0] = initCase.first ? INF : 1;
            dp[2][0] = (!initCase.first && !initCase.second && (enemyList[0][0] + enemyList[1][0] <= w)) ? 1 : 2;

            for(int i=1; i<n; i++) {
                bool innerFlag = enemyList[0][i-1] + enemyList[0][i] <= w;
                bool outerFlag = enemyList[1][i-1] + enemyList[1][i] <= w;
                bool verticalFlag = enemyList[0][i] + enemyList[1][i] <= w;

                if(innerFlag) {
                    dp[0][i] = min(dp[1][i-1]+1, dp[2][i-1]+1);
                } else {
                    dp[0][i] = dp[2][i-1]+1;
                }

                if(outerFlag) {
                    dp[1][i] = min(dp[0][i-1]+1, dp[2][i-1]+1);
                } else {
                    dp[1][i] = dp[2][i-1]+1;
                }

                if(verticalFlag) {
                    dp[2][i] = min(dp[2][i-1]+1, min(dp[0][i]+1, dp[1][i]+1));
                } else {
                    dp[2][i] = min(dp[0][i]+1, dp[1][i]+1);
                }
                if(innerFlag && outerFlag) {
                    if(i>1) {
                        dp[2][i] = min(dp[2][i], dp[2][i-2]+2);
                    } else if(!initCase.first && !initCase.second) {
                        dp[2][i] = min(dp[2][i], 2);
                    }

                }
            } 

            if(initCase.first && initCase.second) {
                minNum = min(minNum, dp[2][n-2]);
            } else if(initCase.first) {
                minNum = min(minNum, dp[1][n-1]);
            } else if(initCase.second) {
                minNum = min(minNum, dp[0][n-1]);  
            } else {
                minNum = min(minNum, dp[2][n-1]);
            }
        }

        cout << minNum << "\n";
    }

}