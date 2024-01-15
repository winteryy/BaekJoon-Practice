#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, s;

    cin >> n >> s;

    vector<int> arr(n+1);
    arr[n] = 987654321;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int l=0, r=0;
    int currentSum=arr[0];
    int minLength=100001;

    while(r<n && l<n) {
        if(currentSum>=s) {
            minLength = min(minLength, r-l+1);
            currentSum -= arr[l];
            l++;
        } else {
            r++;
            currentSum += arr[r];
        }
    }

    cout << (minLength==100001 ? 0 : minLength);

}