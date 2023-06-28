#include <iostream>
#include <algorithm>

using namespace std;

int cost[101];
int mem[101];
int dp[101][10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> mem[i];
    }
    for(int i=1; i<=n; i++){
        cin >> cost[i];
    }

    int costLimit = n * 100;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=costLimit; j++){
            if(cost[i]<=j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]]+mem[i]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=0; i<=costLimit; i++){
        if(dp[n][i]>=m){
            cout << i;
            break;
        }
    }
}