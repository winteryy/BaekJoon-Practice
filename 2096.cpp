#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > dp(3, {0, 0}); //{min, max}
    for(int play=0; play<n; play++) {
        int left, mid, right;
        pair<int, int> leftP, midP, rightP;
        cin >> left >> mid >> right;

        leftP.first = min(dp[0].first+left, dp[1].first+left);
        leftP.second = max(dp[0].second+left, dp[1].second+left);

        midP.first = min(dp[0].first+mid, min(dp[1].first+mid, dp[2].first+mid));
        midP.second = max(dp[0].second+mid, max(dp[1].second+mid, dp[2].second+mid));

        rightP.first = min(dp[1].first+right, dp[2].first+right);
        rightP.second = max(dp[1].second+right, dp[2].second+right);

        dp[0] = leftP;
        dp[1] = midP;
        dp[2] = rightP;
    }

    cout << max(dp[0].second, max(dp[1].second, dp[2].second)) << " " << min(dp[0].first, min(dp[1].first, dp[2].first));

} 