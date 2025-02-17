#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int orig, dest, cost;
};

int n, m;
vector<vector<pair<int, int> > > adjList;
vector<vector<pair<int, pair<int, int> > > > revAdjList;
vector<int> indeg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    adjList = vector<vector<pair<int, int> > >(n+1);
    revAdjList = vector<vector<pair<int, pair<int, int> > > >(n+1);
    indeg = vector<int>(n+1, 0);

    int orig, dest, cost;
    for(int i=0; i<m; i++) {
        cin >> orig >> dest >> cost;
        adjList[orig].push_back({dest, cost});
        revAdjList[dest].push_back({i, {orig, cost}});
        indeg[dest]++;
    }
    cin >> orig >> dest;

    vector<int> dist(n+1, 0);
    queue<int> q;
    q.push(orig);

    while(!q.empty()) {
        int curNode = q.front();
        q.pop();

        for(auto edge: adjList[curNode]) {
            int adjNode = edge.first;
            int adjCost = edge.second;
            indeg[adjNode]--;
            dist[adjNode] = max(dist[adjNode], dist[curNode]+adjCost);
            
            if(indeg[adjNode]==0) {
                q.push(adjNode);
            } 
        }
    }

    vector<bool> isVisited(n+1, false);
    set<int> maxEdges;
    q.push(dest);

    while(!q.empty()) {
        int curNode = q.front();
        q.pop();

        if(isVisited[curNode]) continue;
        isVisited[curNode] = true;

        for(auto edge: revAdjList[curNode]) {
            int adjNode = edge.second.first;
            int adjCost = edge.second.second;
            int edgeInd = edge.first;
            
            if(dist[curNode]-adjCost == dist[adjNode]) {
                maxEdges.insert(edgeInd);
                if(!isVisited[adjNode]) {
                    q.push(adjNode);
                }
            }
        }
    }

    cout << dist[dest] << "\n" << maxEdges.size();
}