#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int snakeLadder[101] = {0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int dest, target;

    for(int i=0; i<n+m; i++) {
        cin >> dest >> target;
        snakeLadder[dest] = target;
    }

    vector<int> dp(101, 101);
    dp[1] = 0;
 
    for(int i=1; i<100; i++) {
        if(dp[i]==101) continue;
        int dirtyMin = i;
        for(int j=1; j<=6; j++) {
            int next = i+j;
            if(next<=100) {
                if(snakeLadder[next]==0) {
                    dp[next] = min(dp[next], dp[i]+1);
                } else {
                    if(snakeLadder[next]<i && dp[snakeLadder[next]]>dp[i]+1) {
                        dirtyMin = snakeLadder[next]-1;
                    }
                    dp[snakeLadder[next]] = min(dp[snakeLadder[next]], dp[i]+1);
                }
            }
        }
        i = dirtyMin;
    }

    cout << dp[100];
}