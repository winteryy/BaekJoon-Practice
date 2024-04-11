#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    vector<int> accArr(n, 0);
    vector<int> exceptAccArr(n, 0);
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int maxSum = arr[0];
    accArr[0] = arr[0];
    exceptAccArr[0] = 0;

    for(int i=1; i<n; i++) {
        accArr[i] = max(arr[i], accArr[i-1]+arr[i]);
        exceptAccArr[i] = max(accArr[i-1], exceptAccArr[i-1]+arr[i]);
        maxSum = max(maxSum, max(accArr[i], exceptAccArr[i]));
    }

    cout << maxSum;
}
