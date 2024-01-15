#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> costs(n);
    vector<int> budgets(m);

    for(int i=0; i<n; i++) {
        cin >> costs[i];
    }
    for(int i=0; i<m; i++) {
        cin >> budgets[i];
    }

    sort(costs.begin(), costs.end());
    sort(budgets.begin(), budgets.end());

    int ans = 0;
    int l=0, r=min(n, m);

    while(l<=r) {
        int mid = (l+r)/2;

        long long money = x;
        for(int i=0; i<mid; i++) {
            if(costs[i]>budgets[m-mid+i]) {
                money-=(costs[i]-budgets[m-mid+i]);
            }
        }
        if(money>=0) {
            ans = max(ans, mid);
            l = mid+1;
        }else {
            r = mid-1;
        }
    }

    cout << ans;
}