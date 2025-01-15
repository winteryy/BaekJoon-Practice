#include <iostream>

using namespace std;

int arr[10000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int sum = arr[0];
    int l = 0, r = 0;
    int cnt = 0;
    while(l<n && r<n) {
        if(sum == m) {
            cnt++;
            sum += arr[++r];
        } else if(sum < m) {
            sum += arr[++r];
        } else {
            sum -= arr[l++];
        }
    }

    cout << cnt;
}