#include <iostream>
#include <vector>
#define MOD 10007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int len = s.length();
    int ans = 0;

    vector<vector<int> > dp(len, vector<int>(len, 0));

    for(int i=0; i<len; i++) {
        dp[i][i] = 1;
        if(i+1<len) {
            dp[i][i+1] = s[i]==s[i+1] ? 3 : 2;
        }
    }

    for(int i=2; i<len; i++) {
        for(int j=0; j<len; j++) {
            int end = i+j;
            if(end>=len) break;

            dp[j][end] = dp[j+1][end] + dp[j][end-1] - dp[j+1][end-1];
            if(s[j]==s[end]) {
                dp[j][end] += dp[j+1][end-1] + 1;
            }
            if(dp[j][end]>=0) {
                dp[j][end] %= MOD;
            } else {
                dp[j][end] = (dp[j][end] % MOD) + MOD;
            }
        }
    }
    cout << dp[0][len-1];
}