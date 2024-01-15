#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> moneyPlan(n);

    for(int i=0; i<n; i++) {
        cin >> moneyPlan[i];
    }

    int l=1, r=1000000000;
    int minMoney = 1000000000;
    while(l<=r) {
        int mid = (l+r)/2;
        int cnt = 0, pocketMoney = 0;

        for(auto money : moneyPlan) {
            if(money>mid) {
                cnt = -1;
                break;
            }

            if(pocketMoney>=money) {
                pocketMoney-=money;
            }else {
                cnt++;
                pocketMoney = mid-money;
            }
        }

        if(cnt==-1) {
            l = mid+1;
        }else if(cnt<=m) {
            minMoney = min(minMoney, mid);
            r = mid-1;
        }else {
            l = mid+1;
        }
    }

    cout << minMoney;
}