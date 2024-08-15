#include <iostream>
#define QUOTIENT 1000000000;

using namespace std;

int dp[10][101][1024] = {0, };

int main() {
    int n;
    cin >> n;

    dp[1][1][2] = 1;
    dp[2][1][4] = 1;
    dp[3][1][8] = 1;
    dp[4][1][16] = 1;
    dp[5][1][32] = 1;
    dp[6][1][64] = 1;
    dp[7][1][128] = 1;
    dp[8][1][256] = 1;
    dp[9][1][512] = 1;

    for(int i=1; i<n; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<1024; k++) {
                if(j!=0) {
                    dp[j-1][i+1][k|1<<j-1] = (dp[j-1][i+1][k|(1<<j-1)] + dp[j][i][k])%QUOTIENT;
                }
                if(j!=9) {
                    dp[j+1][i+1][k|1<<j+1] = (dp[j+1][i+1][k|(1<<j+1)] + dp[j][i][k])%QUOTIENT;
                } 
            }
        }
    }

    int sum = 0;

    for(int i=0; i<10; i++) {
        sum = (sum+dp[i][n][1023])%QUOTIENT;
    }

    cout << sum;
}