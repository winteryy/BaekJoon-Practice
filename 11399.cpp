#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> t(n);
    for(int i=0; i<n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int result = 0;
    for(int i=0; i<n; i++) {
        result += t[i] * (n-i);
    }

    cout << result;
}