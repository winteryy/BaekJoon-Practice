#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n);
    int lis = 1;
    
    for(int i=0; i<n; i++) {
        dp[i] = 1;

        for(int j=0; j<i; j++) {
            if(arr[j]<arr[i]) {
                dp[i] = max(dp[j]+1, dp[i]);
                lis = max(dp[i], lis);
            }
        }
    }

    cout << lis;

}