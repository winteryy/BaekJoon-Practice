#include <iostream>

using namespace std;

int main() {
    int n, f;
    cin >> n >> f;

    n = n / 100 * 100;

    for(int i=n; i<n+99; i++) {
        if(i%f==0) {
            if(i%100 < 10) {
                cout << "0";
            }
            cout << i%100;

            break;
        }
    }
}