#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;

    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> n;
        vector<vector<int> > stickerList(n+1, vector<int>(2));
        for(int j=1; j<=n; j++) {
            cin >> stickerList[j][0];
        }   
        for(int j=1; j<=n; j++) {
            cin >> stickerList[j][1];
        }   
    
        vector<vector<int> > dp(n+1, vector<int>(3, 0)); // 위 선택, 아래 선택, 미선택    

        for(int j=1; j<=n; j++) {
            dp[j][0] = max(dp[j-1][1]+stickerList[j][0], dp[j-1][2]+stickerList[j][0]);
            dp[j][1] = max(dp[j-1][0]+stickerList[j][1], dp[j-1][2]+stickerList[j][1]);
            dp[j][2] = max(dp[j-1][2], max(dp[j-1][0], dp[j-1][1]));                        
        }

        cout << max(dp[n][2], max(dp[n][0], dp[n][1])) << "\n";
    }

}