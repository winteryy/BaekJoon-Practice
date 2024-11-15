#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coinList(n);
    for(int i=0; i<n; i++) {
        cin >> coinList[i];
    }

    int num = 0;
    for(int i=n-1; i>=0; i--) {
        num += k/coinList[i];
        k %= coinList[i];
    }

    cout << num;
}