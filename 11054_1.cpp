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

    vector<int> lis(n, 1);
    vector<int> lds(n, 1);

    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            if(numArr[j]<numArr[i]) {
                lis[i] = max(lis[i], lis[j]+1);
            }
        }

        int ldsInd = n-1-i;
        for(int j=ldsInd+1; j<n; j++) {
            if(numArr[j]<numArr[ldsInd]) {
                lds[ldsInd] = max(lds[ldsInd], lds[j]+1);
            }
        }
    }

    int longestLength = 0;
    for(int i=0; i<n; i++) {
        longestLength = max(longestLength, lis[i]+lds[i]-1);
    }

    cout << longestLength;
}