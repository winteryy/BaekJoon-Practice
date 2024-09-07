#include <iostream>
#define MOD 10007

using namespace std;

int dp[1001][1001];

int binomialCoefficient(int n, int k) {
    if(k==0) return 1;
    if(k==n) return 1;

    if(dp[n][k]==0) { 
        dp[n][k] = (binomialCoefficient(n-1, k-1) + binomialCoefficient(n-1, k)) % MOD;
    }
    return dp[n][k];
}

int main() {
    int n, k;

    cin >> n >> k;

    cout << binomialCoefficient(n, k);
}