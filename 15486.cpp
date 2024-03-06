#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int, int> > schedule(n);

    for(int i=0; i<n; i++) {
        cin >> schedule[i].first >> schedule[i].second;
    }

    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=0; i--) {
        if(i+schedule[i].first<=n) {
            dp[i] = max(dp[i+1], schedule[i].second+dp[i+schedule[i].first]);
        }else {
            dp[i] = dp[i+1];
        }
    }

    cout << dp[0];
}