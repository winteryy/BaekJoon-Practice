#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            cout << " ";
        }
        for(int j=0; j<n-i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}