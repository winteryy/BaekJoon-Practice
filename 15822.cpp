#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> xArr(n);
    vector<int> yArr(n);
    vector<vector<int> > dp(n+1, vector<int>(n+1, 987654321));

    for(int i=0; i<n; i++) {
        cin >> xArr[i];
    }

    for(int i=0; i<n; i++) {
        cin >> yArr[i];
    }

    dp[0][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int diff = xArr[i-1]-yArr[j-1];
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + diff*diff;
        }
    }


    cout << dp[n][n];
}