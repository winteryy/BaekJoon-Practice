#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<vector<int> > costVector(n+1, vector<int>(3, 0));

    for(int i=1; i<=n; i++) {
        cin >> costVector[i][0] >> costVector[i][1] >> costVector[i][2];
    }

    vector<vector<int> > dp(n+1, vector<int>(3, 0));

    for(int i=1; i<=n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costVector[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costVector[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costVector[i][2];
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);

}