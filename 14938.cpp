#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> items(n+1);
    for(int i=1; i<=n; i++) {
        cin >> items[i];
    }

    vector<vector<pair<int, int> > > adjList(n+1);
    int a, b, l;

    for(int i=0; i<r; i++) {
        cin >> a >> b >> l;
        adjList[a].push_back({b, l});
        adjList[b].push_back({a, l});
    }

    int maxItemValueSum = 0;
    for(int i=1; i<=n; i++) {
        vector<int> dist(n+1, INF);
        priority_queue<pair<int, int> > pq; //{-cost, target}
        pq.push({0, i});

        int getItemValueSum = 0;
        while(!pq.empty()) {
            int curCost = -pq.top().first;
            int curNode = pq.top().second;
            pq.pop();

            if(curCost>=dist[curNode]) continue;
            if(curCost<=m) getItemValueSum += items[curNode];
            dist[curNode] = curCost;

            for(auto edge: adjList[curNode]) {
                if(dist[edge.first]>=curCost+edge.second) {
                    pq.push({-(curCost+edge.second), edge.first});
                }
            }
        }
        maxItemValueSum = max(maxItemValueSum, getItemValueSum);
    }

    cout << maxItemValueSum;
}