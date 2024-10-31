#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    int h, o;
    cin >> n;
    vector<pair<int, int> > positions(n); //{o, h}

    for(int i=0; i<n; i++) {
        cin >> positions[i].first >> positions[i].second;
        if(positions[i].second>positions[i].first) {
            swap(positions[i].second, positions[i].first);
        }
    }
    cin >> d;

    sort(positions.begin(), positions.end());

    priority_queue<int, vector<int>, greater<int> > pq;

    uint64_t maxNum = 0;
    int prev;
    for(int i=0; i<n; i++) {
        prev = positions[i].first-d;
        while(!pq.empty() && pq.top()<prev) {
            pq.pop();
        }
        if(positions[i].first-positions[i].second<=d) pq.push(positions[i].second);

        maxNum = max(maxNum, pq.size());
    }

    cout << max(maxNum, pq.size());

}