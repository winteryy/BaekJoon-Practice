#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> stair(n+2, 0);
    vector<vector<int> > dp(n+2, vector<int>(2, 0));

    for(int i=2; i<n+2; i++) {
        cin >> stair[i];
    }
    for(int i=2; i<n+2; i++) {
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + stair[i];
        dp[i][1] = dp[i-1][0]+stair[i];
    }

    cout << max(dp[n+1][0], dp[n+1][1]);
}