#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

struct cmp {
    bool operator()(pair<short, int>& l, pair<short, int>& r) {
        return l.second > r.second;
    }
};

vector<vector<pair<short, int> > > adjList; //node, cost
vector<pair<int, short> > costs; //costSum, prevNode
priority_queue<pair<short, int>, vector<pair<short, int> >, cmp > pq;

void dijkstra(int start, int target) {

    for(auto edge: adjList[start]) {
        costs[edge.first] = {min((int)edge.second, costs[edge.first].first), start};
        pq.push({edge.first, edge.second});
    }

    while(!pq.empty()) { //node, cost
        auto curNode = pq.top().first;
        auto curCost = pq.top().second;
        pq.pop();

        if(curCost > costs[curNode].first) continue;

        if(curNode==target) {
            break;
        }

        for(auto edge: adjList[curNode]) {
            auto nextNode = edge.first;
            auto newCost = costs[curNode].first+edge.second;

            if(costs[nextNode].first>newCost) {
                costs[nextNode] = {newCost, curNode};
                pq.push({nextNode, newCost});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, start, target, cost;
    cin >> n >> m;

    adjList.assign(n+1, vector<pair<short, int> >());

    for(int i=0; i<m; i++) {
        cin >> start >> target >> cost;

        adjList[start].push_back({target, cost});
    }

    cin >> start >> target;
    
    costs.assign(n+1, {INF, 0});
    costs[start] = {0, start};

    dijkstra(start, target);

    deque<int> dq;
    int node = target;
    while(node!=start) {
        dq.push_front(node);
        node = costs[node].second;
    }
    dq.push_front(start);
    
    cout << costs[target].first << "\n" << dq.size() << "\n";
    for(auto vertex: dq) {
        cout << vertex << " ";
    }
    
}