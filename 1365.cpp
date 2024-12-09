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

    vector<int> lis;
    lis.push_back(arr[0]);

    for(int i=1; i<n; i++) {
        if(arr[i]>lis[lis.size()-1]) {
            lis.push_back(arr[i]);
        } else {
            *lower_bound(lis.begin(), lis.end(), arr[i]) = arr[i];
        }
    }

    cout << n-lis.size();
}