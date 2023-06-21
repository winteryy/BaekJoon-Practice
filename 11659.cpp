#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums(n+1);
    vector<int> dp(n+1, 0);

    for(int i=1; i<=n; i++){
        cin >> nums[i];
    }

    for(int i=0; i<n; i++){
        dp[i+1] = dp[i] + nums[i+1];
    }

    int start, end;

    for(int i=0; i<m; i++){
        cin >> start >> end;
        cout << dp[end] - dp[start-1] << "\n";
    }
}