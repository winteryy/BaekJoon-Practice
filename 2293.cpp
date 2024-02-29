#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> coins(n);
    vector<int> dp(k+1, 0);

    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;

    for(auto c: coins) {
        for(int i=0; i+c<=k; i++) {
            dp[i+c] += dp[i];
        }
    }

    cout << dp[k];
}