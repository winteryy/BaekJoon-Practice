#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    long m;

    cin >> n >> m;

    vector<long> trees(n);
    for(int i=0; i<n; i++) {
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end());

    int l=0, r=1000000000;
    int maxHeight= 0;
    while(l<=r) {
        
        int mid = (l+r)/2;
        long total = 0;
        for(int i=0; i<n; i++) {
            total += (trees[i]>mid ? trees[i]-mid : 0);
        }

        if(total<m) {
            r = mid-1;
        }else {
            maxHeight = max(maxHeight, mid);
            l = mid+1;
        }
    }

    cout << maxHeight;
}