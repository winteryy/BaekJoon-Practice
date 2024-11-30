#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool dp[4][50001];

int main() {
    int n;
    cin >> n;  

    memset(dp, false, sizeof(dp));

    vector<int> squares;
    for(int i=1; i*i<=n; i++) {
        squares.push_back(i*i);
    }

    for(auto square: squares) {
        dp[0][square] = true;
    }

    for(int i=0; i<3; i++) {
        for(int j=1; j<n; j++) {
            if(!dp[i][j]) continue;
            for(auto square: squares) {
                int sum = j+square;
                if(sum <= n) {
                    dp[i+1][sum] = true;
                }
            }
        }
    }

    for(int i=0; i<4; i++) {
        if(dp[i][n]) {
            cout << i+1;
            break;
        }
    }
}