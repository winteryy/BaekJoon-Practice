#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arrA(n);
    vector<int> arrB(n);

    for(int i=0; i<n; i++) {
        cin >> arrA[i];
    }
    for(int i=0; i<n; i++) {
        cin >> arrB[i];
    }

    sort(arrA.begin(), arrA.end());
    sort(arrB.begin(), arrB.end(), greater<int>());
    
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arrA[i]*arrB[i];
    }

    cout << sum;
}