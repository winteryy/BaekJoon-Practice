#include <iostream>

using namespace std;

typedef long long ll;

ll arr[1000001] = {0,};
ll cnt[1001] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
        arr[i] %= m;
        cnt[arr[i]]++;
    }
    
    ll result = cnt[0];

    for(int i=0; i<m; i++){
        result += cnt[i] * (cnt[i]-1) /2;
    }

    cout << result;

}