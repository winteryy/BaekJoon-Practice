#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> wines(n+1);

    for(int i=1; i<=n; i++) {
        cin >> wines[i];
    }

    vector<vector<int> > dp(3, vector<int>(n+1, 0)); //0: not select   1: n select only n   2: n-1 select both

    for(int i=1; i<=n; i++) {
        dp[0][i] = max(dp[0][i-1], max(dp[1][i-1], dp[2][i-1]));
        dp[1][i] = dp[0][i-1] + wines[i];
        dp[2][i] = dp[1][i-1] + wines[i];
    }

    cout << max(dp[0][n], max(dp[1][n], dp[2][n]));
}