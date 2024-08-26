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
    vector<int> prev(n, -1);
    vector<int> lisInd;

    dp.push_back(arr[0]);
    lisInd.push_back(0);

    for(int i=1; i<n; i++) {
        if(dp[dp.size()-1]<arr[i]) {
            dp.push_back(arr[i]);
            lisInd.push_back(i);
            prev[i] = lisInd[lisInd.size()-2];
        } else {
            auto lb = lower_bound(dp.begin(), dp.end(), arr[i]);
            *lb = arr[i];
            lisInd[lb-dp.begin()] = i;
            if(lb-dp.begin()>0) {
                prev[i] = lisInd[lb-dp.begin()-1];
            }

        }
    }

    vector<int> lis;
    for(int i=lisInd[lisInd.size()-1]; i!=-1; i=prev[i]) {
        lis.push_back(arr[i]);
    }

    cout << dp.size() << '\n';
    for(int i=lis.size()-1; i>=0; i--) {
        cout << lis[i] << " ";
    }
}