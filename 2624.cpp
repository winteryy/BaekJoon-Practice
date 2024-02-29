#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, k;
    cin >> t >> k;
    vector<int> dp(t+1);
    dp[0] = 1;

    for(int i=0; i<k; i++) {
        int p, n;
        cin >> p >> n;

        for(int j=t; j>=0; j--) {
            for(int cnt=1; cnt<=n; cnt++) {
                int val = j+p*cnt;
                if(val>t) break; 
                dp[val] += dp[j];
            }
        }
    }

    cout << dp[t];
}