#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, num;
    vector<int> numList;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> num;
        numList.push_back(num);
    }

    sort(numList.begin(), numList.end());

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> num;
        cout << binary_search(numList.begin(), numList.end(), num) << "\n";
    }
}