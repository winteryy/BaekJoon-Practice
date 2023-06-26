#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int n;
        cin >> n;
        vector<int> sums(n+1, 0);
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int i=1; i<=n; i++){
            cin >> sums[i];
            sums[i] += sums[i-1];
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<=n-i; j++){
                dp[j][j+i] = INF;
                for(int k=j; k<j+i; k++){
                    dp[j][j+i] = min(dp[j][j+i], dp[j][k]+dp[k+1][j+i]+sums[j+i]-sums[j-1]);
                }

            }
        }

        cout << dp[1][n] << "\n";
    }



}