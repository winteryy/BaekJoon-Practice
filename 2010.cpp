#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = 1, num;
    for(int i=0; i<n; i++) {
        cin >> num;
        sum--;
        sum+=num;
    }

    cout << sum;
}