#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000000];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> dp;
    dp.push_back(arr[0]);

    for(int i=1; i<n; i++) {
        if(dp[dp.size()-1]<arr[i]) {
            dp.push_back(arr[i]);
        } else {
            *(lower_bound(dp.begin(), dp.end(), arr[i])) = arr[i];
        }
    }

    cout << dp.size();
}