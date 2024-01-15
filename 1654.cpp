#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int k, n;
    cin >> k >> n;

    vector<int> lanArr(k);
    for(int i=0; i<k; i++) {
        cin >> lanArr[i];
    }


    long longestLength=0;
    long l = 0, r = (1<<31)-1;

    while(l<=r) {
        int totalSum = 0;
        long mid = (l+r)/2;

        for(int i=0; i<k; i++) {
            totalSum += lanArr[i]/mid;
        }

        if(totalSum>=n) {
            longestLength = max(longestLength, mid);
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    cout << longestLength;
}