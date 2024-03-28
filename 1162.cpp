#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 999987654321

using namespace std;

typedef long long int ll;

struct cmp {
    bool operator()(pair<pair<int, ll>, int>& l, pair<pair<int, ll>, int>& r) {
        if(l.first.second==r.first.second) {
            return l.second > r.second;
        }else {
            return l.first.second > r.first.second;
        }
    }
};

vector<vector<pair<int, int> > > adjList; //node, cost
vector<vector<ll> > costs;
priority_queue<pair<pair<int, ll>, int>, vector<pair<pair<int, ll>, int> >, cmp > pq;

int n, m, k;

void dijkstra() {

    for(auto edge: adjList[1]) {
        costs[0][edge.first] = min((ll)edge.second, costs[0][edge.first]);
        pq.push({{edge.first, edge.second}, 0});

        costs[1][edge.first] = 0;
        pq.push({{edge.first, 0}, 1});
    }

    while(!pq.empty()) { // {{node, cost}, covered}
        int curNode = pq.top().first.first;
        ll curCost = pq.top().first.second;
        int curCovered = pq.top().second;
        pq.pop();
        
        bool flag = false;
        for(int i=0; i<curCovered; i++) {
            if(costs[i][curNode]<=curCost) {
                flag = true;
                break;
            }
        }
        if(costs[curCovered][curNode]<curCost) flag = true;

        if(flag) continue;

        if(curNode==n) {
            cout << curCost;
            break;
        }

        for(auto edge: adjList[curNode]) {
            auto nextNode = edge.first;
            auto newCost = curCost+edge.second;

            if(costs[curCovered][nextNode]>newCost) {
                costs[curCovered][nextNode] = newCost;
                pq.push({{nextNode, newCost}, curCovered});
            }
            if(curCovered<k && costs[curCovered+1][nextNode]>curCost) {
                costs[curCovered+1][nextNode] = curCost;
                pq.push({{nextNode, curCost}, curCovered+1});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    adjList.assign(n+1, vector<pair<int, int> >());

    int start, target, cost;

    for(int i=0; i<m; i++) {
        cin >> start >> target >> cost;

        adjList[start].push_back({target, cost});
        adjList[target].push_back({start, cost});
    }
    
    costs.assign(k+1, vector<ll>(n+1, INF));
    costs[0][1] = 0;

    dijkstra();
    
}