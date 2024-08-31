#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isRightAngle(int a, int b, int c) {
    vector<int> arr = {a, b, c};
    sort(arr.begin(), arr.end());

    if(arr[0]*arr[0]+arr[1]*arr[1] == arr[2]*arr[2]) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x, y, z;
    cin >> x >> y >> z;

    while(x != 0) {
        cout << (isRightAngle(x, y, z) ? "right\n" : "wrong\n");
        cin >> x >> y >> z; 
    }
}