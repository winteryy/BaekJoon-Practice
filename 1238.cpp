#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 987654321

using namespace std;

class Node{
public: 
    vector<pair<int, int> > edges;

};

int main() {
    int n, e, x;
    cin >> n >> e >> x;

    vector<Node> nodes(n+1, Node());

    for(int i=0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        nodes[u].edges.push_back(make_pair(v, w));
    }

    vector<int> totalDist(n+1, 0); //total distance u->v + v->u
    for(int i=1; i<=n; i++) {
        vector<int> dists(n+1, INF);

        if(i!=x) {
            priority_queue<pair<int, int> > pq; //(totalWeight, currentNode)   
            for(auto j: nodes[i].edges) {
                dists[j.first] = j.second;
                pq.push(make_pair(-j.second, j.first));
            }
            vector<bool> isVisited(n+1, false);
            isVisited[i] = true;

            while(!pq.empty()) {
                int currentWeight = -(pq.top().first);
                int currentNode = pq.top().second;
                pq.pop();

                if(currentNode==x) {
                    totalDist[i]+=currentWeight;
                    break;
                }
                
                if(isVisited[currentNode]) {
                    continue;
                }
                isVisited[currentNode] = true;

                for(auto j: nodes[currentNode].edges) {
                    if(!isVisited[j.first] && dists[j.first]>dists[currentNode]+j.second) {
                        pq.push(make_pair(-(currentWeight+j.second), j.first));
                        dists[j.first] = dists[currentNode]+j.second;
                    }
                }
            }
        } else {
            priority_queue<pair<int, int> > pq; //(totalWeight, currentNode)   
            for(auto j: nodes[i].edges) {
                dists[j.first] = j.second;
                pq.push(make_pair(-j.second, j.first));
            }
            vector<bool> isVisited(n+1, false);
            isVisited[i] = true;

            while(!pq.empty()) {
                int currentWeight = -(pq.top().first);
                int currentNode = pq.top().second;
                pq.pop();
                
                if(isVisited[currentNode]) {
                    continue;
                }
                isVisited[currentNode] = true;

                for(auto j: nodes[currentNode].edges) {
                    if(!isVisited[j.first] && dists[j.first]>dists[currentNode]+j.second) {
                        pq.push(make_pair(-(currentWeight+j.second), j.first));
                        dists[j.first] = dists[currentNode]+j.second;
                    }
                }
            }

            for(int j=1; j<=n; j++) {
                if(j!=x) {
                    totalDist[j] += dists[j];
                }
            }
        }
    }

    int maxDist = *max_element(totalDist.begin(), totalDist.end());
    cout << maxDist;
}