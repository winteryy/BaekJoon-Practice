#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    cin >> n;

    int maxNum = -1001;
    int curSum = 0;
    for(int i=0; i<n; i++) {
        cin >> num;
        
        if(curSum+num < num) {
            curSum = num;
        } else {
            curSum += num;
        }

        maxNum = max(maxNum, curSum);
    }

    cout << maxNum;
}