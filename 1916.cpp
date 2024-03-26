#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

struct cmp {
    bool operator()(pair<int, int> l, pair<int, int> r) {
        return l.second > r.second;
    }
};

int main() {
    int n, m, start, target, cost;
    cin >> n >> m;

    vector<vector<pair<int, int> > > adjList(n+1, vector<pair<int, int> >());

    for(int i=0; i<m; i++) {
        cin >> start >> target >> cost;

        adjList[start].push_back({target, cost});
    }

    cin >> start >> target;
    
    vector<int> costs(n+1, INF);
    vector<bool> isVisited(n+1, false);
    costs[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > pq;
    
    for(auto edge: adjList[start]) {
        costs[edge.first] = min(costs[edge.first], edge.second);
        pq.push({edge.first, edge.second});
    }

    isVisited[start] = true;

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        if(isVisited[top.first]) continue;

        if(top.first==target) {
            cout << top.second;
            break;
        }
        isVisited[top.first] = true;

        for(auto edge: adjList[top.first]) {
            if(!isVisited[edge.first]) {
                if(costs[edge.first]>costs[top.first]+edge.second) {
                    costs[edge.first] = costs[top.first]+edge.second;
                    pq.push({edge.first, costs[edge.first]});
                }
            }
        }
    }
}