#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, k;
int main(){

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    ll lo=1, hi=k*k, mid;
    ll res = 0;

    while(lo<=hi){
        mid = (lo+hi)/2;

        ll cnt = 0;
        for(int i=1; i<=n; i++){
            cnt += min(n, (ll)mid/i);
            if(i>mid){
                break;
            }
        }
        if(cnt >= k){
            res = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    
    cout << res;
}