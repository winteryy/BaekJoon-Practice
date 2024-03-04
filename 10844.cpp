#include <iostream>
#include <vector>
#define MOD_NUM 1000000000

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > dp(10, vector<int>(n, 0));
    for(int i=1; i<=9; i++) {
        dp[i][0] = 1;
    }
    
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<=9; j++) {
            if(j-1>=0) dp[j-1][i+1] = (dp[j-1][i+1]+dp[j][i])%MOD_NUM;
            if(j+1<=9) dp[j+1][i+1] = (dp[j+1][i+1]+dp[j][i])%MOD_NUM;
        }
    }

    int num = 0;
    for(int i=0; i<=9; i++) {
        num = (num+dp[i][n-1])%MOD_NUM;
    }

    cout << num;
}