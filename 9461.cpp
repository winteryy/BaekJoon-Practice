#include <iostream>

using namespace std;

long long dp[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[3]=dp[2]=dp[1]=1;
    dp[5]=dp[4]=2;

    for(int i=6; i<=100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        cout << dp[n] << "\n";
    }

}