#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

long long menuList[300000];

long long bigPow(long long base, long long exp) {
    if(exp==0) return 1;
    if(exp==1) return base;

    long long half = bigPow(base, exp/2);
    if(exp%2==0) {
        return half*half%MOD;
    } else {
        return half*half%MOD*base%MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> menuList[i];
    }

    sort(menuList, menuList+n);

    long long result = 0;

    for(int i=0; i<n; i++) {
        long long maxCnt = bigPow(2, i)-1;
        long long minCnt = bigPow(2, n-i-1)-1;
        
        result += menuList[i]*(maxCnt-minCnt);
        result %= MOD;
    }

    cout << result;
}