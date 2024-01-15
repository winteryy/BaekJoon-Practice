#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int l=0, r=0;
    int minSum=2000000001;

    while(l<n && r<n) {
        if(arr[r]-arr[l]>=m) {
            minSum = min(minSum, arr[r]-arr[l]);
            l++;
        } else {
            r++;
        }
    }

    cout << minSum;
}