#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> accSum;
vector<vector<int> > dp;

int sectionSum(int i, int j) {
    return accSum[j] - accSum[i-1];
}

int calc(int n, int m) {
    if(m == 0) return 0;
    if(n <= 0) return -1000000000;

    if(dp[n][m] != -1) return dp[n][m];

    dp[n][m] = calc(n-1, m);
    for(int i=1; i<=n; i++) {
        dp[n][m] = max(dp[n][m], calc(i-2, m-1)+sectionSum(i, n));
    }
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    arr = vector<int>(n+1, 0);
    accSum = vector<int>(n+1, 0);
    dp = vector<vector<int> >(n+1, vector<int>(m+1, -1));

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        accSum[i] = accSum[i-1] + arr[i];
    }

    cout << calc(n, m);
}