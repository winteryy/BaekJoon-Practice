#include <iostream>
#define MOD 10007

using namespace std;

int dp[1001];

int main() {
    int n;
    cin >> n;

    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] += dp[i-1] % MOD;
        dp[i] += dp[i-2]*2 % MOD;
    }

    cout << dp[n] % MOD;
}