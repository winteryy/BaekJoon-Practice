#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

struct Road {
    int id, dest, cost;
};

int n, m, s, d;
vector<vector<Road> > adjList;
vector<vector<Road> > rev;
vector<int> dist;
vector<bool> usedEdge;
vector<bool> isVisited;

void dfs(int curNode, int curCost) {
    if(isVisited[curNode]) return;
    isVisited[curNode] = true;

    for(auto& road: rev[curNode]) {
        if(curCost+road.cost+dist[road.dest]==dist[d]) {
            usedEdge[road.id] = true;
            if(!isVisited[road.dest]) {
                dfs(road.dest, curCost+road.cost);
            }
        }
    }
}

void initDijk() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist.assign(n, INF);
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(curCost>dist[curNode]) continue; 
        
        for(auto& road: adjList[curNode]) {
            int newCost = curCost+road.cost;
            if(dist[road.dest]>newCost) {
                pq.push({newCost, road.dest});
                dist[road.dest] = newCost;
            }
        }
    }
}

void dijk() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist.assign(n, INF);
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(curCost>dist[curNode]) continue; 
        
        for(auto& road: adjList[curNode]) {
            int newCost = curCost+road.cost;
            if(dist[road.dest]>newCost && !usedEdge[road.id]) {
                pq.push({newCost, road.dest});
                dist[road.dest] = newCost;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int u, v, p;

    cin >> n >> m;
    while(!(n==0 && m==0)) {
        cin >> s >> d;
        int roadId = 0;
        adjList.assign(n, vector<Road>());
        rev.assign(n, vector<Road>());

        for(int i=0; i<m; i++) {
            cin >> u >> v >> p;
            adjList[u].push_back({roadId, v, p});
            rev[v].push_back({roadId++, u, p});
        }

        usedEdge.assign(m, false);
        isVisited.assign(n, false);

        initDijk();
        dfs(d, 0);
        dijk();

        cout << (dist[d]==INF ? -1 : dist[d]) << "\n";
        cin >> n >> m;
    }

}