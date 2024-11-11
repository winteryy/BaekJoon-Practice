#include<iostream>
#include <vector>
#define MOD 10007

using namespace std;

int dp[53][53]; //dp[i][j] iCj

void initComb() {
    for(int i=1; i<=52; i++) {
        dp[i][0] = dp[i][i] = 1;
        for(int j=0; j<=i/2; j++) {
            dp[i][i-j] = dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }
}

int main() {
    int n;
    cin >> n;  
    dp[0][0] = 1;
    initComb();

    int result = 0;
    for(int i=1; i*4<=n; i++) {
        int num = dp[13][i];
        if(i%2==1) {
            result = (result + (dp[52-i*4][n-i*4] * num) % MOD) % MOD;
        } else {
            result = (result - (dp[52-i*4][n-i*4] * num) % MOD + MOD) % MOD;
        }
    }

    cout << result;
}