#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {

    int n;
    cin >> n;

    vector<int> liquid(n);
    for(int i=0; i<n; i++) {
        cin >> liquid[i];
    }

    sort(liquid.begin(), liquid.end());

    LL minDiff = 3000000001LL;
    int minInd[3];

    for(int i=0; i<n-2; i++) {
        int l = i+1, r = n-1;
        LL diff = 3000000001LL;
        int localMin[2];
        while(l<r) {
            LL sum = (LL)liquid[l]+liquid[r]+liquid[i];
            if(diff>abs(0L-sum)) {
                localMin[0] = l;
                localMin[1] = r;
                diff = abs(0LL-sum);
            }

            if(sum>=0) {
                r--;
            }else {
                l++;
            }
        }
        
        if(diff<minDiff) {
            minDiff = diff;
            minInd[0]=i;
            minInd[1]=localMin[0];
            minInd[2]=localMin[1];
        }
    }

    for(int i=0; i<3; i++) {
        cout << liquid[minInd[i]] << " ";
    }
}