#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for(int i=0; i<n; i++) {
        cin >> t[i];
    }

    LL l=0, r=1000000000LL*m/n+1;
    LL minTime = r;

    while(l<=r) {
        LL mid = (l+r)/2;

        LL totalThroughput = 0;
        for(int i=0; i<n; i++) {
            totalThroughput += mid/t[i];
        }

        if(totalThroughput>=m) {
            minTime = min(minTime, mid);
            r = mid-1;
        }else {
            l = mid+1;
        }
    }

    cout << minTime;
}