#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while(t--) {
        int dp[11] = {0,};
        cin >> n;

        dp[0] = 1;

        for(int i=0; i<n; i++) {
            for(int j=1; j<=3; j++) {
                if(i+j<=n) {
                    dp[i+j] += dp[i];
                }
            }
        }

        cout << dp[n] << "\n";
    }

}