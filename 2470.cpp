#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long n, num;
    cin >> n;

    vector<long> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    pair<long, long> answer = make_pair(0, 2000000000);

    int l=0, r=n-1;

    while(l<r) {
        long sum = v[l] + v[r];

        if(abs(0-(answer.first+answer.second)) > abs(0-sum)) {
            answer.first = v[l];
            answer.second = v[r];

            if(sum == 0) {
                break;
            }
        }

        if(sum<0) {
            l++;
        }else {
            r--;
        }
    }

    cout << answer.first << " " << answer.second;
}
