#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int v, e;
    int startVertex;

    cin >> v >> e >> startVertex;

    vector<vector<pair<int, int> > > edges(v+1);

    for(int i=0; i<e; i++) {
        int u, ve, w;
        cin >> u >> ve >> w;
        
        edges[u].push_back(make_pair(ve, w));
    }

    bool isVisited[v+1] = {false, };
    int dist[v+1];
    for(int i=1; i<=v; i++) {
        dist[i] = INF;
    }
    isVisited[startVertex] = true;
    dist[startVertex] = 0;

    for(int i=0; i<edges[startVertex].size(); i++) {
        pair<int, int> p = edges[startVertex][i];
        dist[p.first] = min(p.second, dist[p.first]);
    }

    priority_queue<pair<int, int> > pq;
    for(int j=1; j<=v; j++) {
        if(!isVisited[j]){
            pq.push(make_pair(-dist[j], j));
        }
    }

    for(int i=0; i<v-1; i++) {
        bool flag = false;
        int nowDist = -1;
        int nowVertex = -1;
        while(!pq.empty()) {
            if(pq.top().first==-INF) {
                flag = true;
                break;
            }
            if(!isVisited[pq.top().second]) {
                nowDist = -(pq.top().first);
                nowVertex = pq.top().second;
                isVisited[nowVertex] = true;
                dist[nowVertex] = nowDist;
                break;
            }
            pq.pop();
        }

        if(flag || nowVertex==-1) {
            break;
        }


        for(int j=0; j<edges[nowVertex].size(); j++) {
            pair<int, int> p = edges[nowVertex][j];
            if(isVisited[p.first]==false) {
                int tempDist = min(dist[p.first], dist[nowVertex]+p.second);
                if(tempDist!=INF) {
                    pq.push(make_pair(-tempDist, p.first));
                }
            }
        }

    }

    for(int i=1; i<=v; i++) {
        if(dist[i]==INF) {
            cout << "INF\n";
        }else {
            cout << dist[i] << "\n";
        }
    }
}