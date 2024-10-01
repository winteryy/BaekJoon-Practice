#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321 

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> isVisited(100001, INF);
    priority_queue<pair<int, int> > pq;  //{-cost, position}

    pq.push({0, n});

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(isVisited[cur.second] <= -cur.first) continue;
        if(cur.second == k) {
            cout << -cur.first;
            break;
        }
        isVisited[cur.second] = -cur.first;

        if(cur.second+1<=100000) {
            pq.push({cur.first-1, cur.second+1});
        }
        if(cur.second-1>=0) {
            pq.push({cur.first-1, cur.second-1});
        }
        if(cur.second*2<=100000) {
            pq.push({cur.first, cur.second*2});
        }
    }
}   