#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_COIN 987654321

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> coins(n);
    vector<int> dp(k+1, MAX_COIN);

    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }

    for(auto c: coins) {
        if(c<=k) dp[c] = 1;
    }

    for(int i=1; i<=k; i++) {
        if(dp[i]!=MAX_COIN) {
            for(auto c: coins) {
                if(i+c<=k) dp[i+c] = min(dp[i+c], dp[i]+1);
            }
        }
    }

    cout << (dp[k]==MAX_COIN ? -1 : dp[k]);
}