#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> lcs;
    lcs.push_back(arr[0]);

    for(int i=1; i<n; i++) {
        if(arr[i]>lcs[lcs.size()-1]) {
            lcs.push_back(arr[i]);
        } else {
            *lower_bound(lcs.begin(), lcs.end(), arr[i]) = arr[i];
        }
    }

    cout << n-lcs.size();
}