#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> numArr(n);
    for(int i=0; i<n; i++) {
        cin >> numArr[i];
    }

    int longestLength = 0;

    for(int i=0; i<n; i++) {
        vector<int> prev;
        vector<int> subs;
        prev.push_back(0);
        subs.push_back(numArr[i]);

        for(int j=0; j<i; j++) {
            if(numArr[j]>=numArr[i]) continue;
            if(numArr[j]>prev.back()) {
                prev.push_back(numArr[j]);
            } else {
                auto pos = lower_bound(prev.begin(), prev.end(), numArr[j]);
                if(pos!=prev.end()) {
                    *pos = numArr[j];
                }
            }
        }

        for(int j=i+1; j<n; j++) {
            if(numArr[j]<subs.back()) {
                subs.push_back(numArr[j]);
            } else {
                auto pos = lower_bound(subs.begin(), subs.end(), numArr[j], greater<int>());
                if(pos!=subs.end() && pos!=subs.begin()) {
                    *pos = numArr[j];
                }
            }
        }

        longestLength = max(longestLength, (int)prev.size() + (int)subs.size() - 1);
    }

    cout << longestLength;
}