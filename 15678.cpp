#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    deque<pair<int, long long> > dq;
    long long ans = INT32_MIN;
    long long num;
    for(int i=0; i<n; i++) {
        cin >> num;
        
        while(!dq.empty() && dq.front().first < i-d) {
            dq.pop_front();
        }
        
        if(!dq.empty()) {
            num = max(num, dq.front().second+num);
        }
        
        while(!dq.empty() && dq.back().second < num) {
            dq.pop_back();
        }

        dq.push_back({i, num});
        ans = max(ans, num);
    }
    
    cout << ans;
}