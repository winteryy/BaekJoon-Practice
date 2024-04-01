#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000

using namespace std;
typedef pair<pair<int, int>, pair<bool, bool> > pp; //{{cost, vertex},{v1Visited, v2Visited}}

struct cmp {
    bool operator() (pp& l, pp& r) {
        int lVisit = l.second.first + l.second.second;
        int rVisit = r.second.first + r.second.second;
        
        if(l.first.first == r.first.first) {
            return lVisit < rVisit;
        }else {
            return l.first.first > r.first.first;
        }

    }
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int> > > adjList(n+1); //vertex, cost
    int a, b, c;
    int v1, v2;

    for(int i=0; i<e; i++) {
        cin >> a >> b >> c;
        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    vector<vector<int> > visited(n+1, vector<int>(4, INF)); //0: none, 1: v1, 2: v2, 3: v1&v2
    priority_queue<pp, vector<pp>, cmp> pq;
    if(v1 == 1) {
        visited[1][1] = 0;
        pq.push({{0, 1}, {true, false}});
    } else {
        visited[1][0] = 0;
        pq.push({{0, 1}, {false, false}});
    }

    while(!pq.empty()) {
        int curCost = pq.top().first.first;
        int curNum = pq.top().first.second;
        bool curV1Flag = pq.top().second.first;
        bool curV2Flag = pq.top().second.second;
        pq.pop();

        int state = (curV2Flag<<1)+curV1Flag;

        if(curNum==n && state==3) {
            cout << curCost;
            return 0;
        }

        if(visited[curNum][state]<curCost) continue;

        for(auto next: adjList[curNum]) {
            int nextNum = next.first;
            int nextCost = curCost+next.second;
            if(nextNum == v1) {
                if(visited[nextNum][state|1]>nextCost) {
                    visited[nextNum][state|1] = nextCost;
                    pq.push({{nextCost, nextNum}, {true, curV2Flag}});
                }
            }else if(nextNum == v2) {
                if(visited[nextNum][state|2]>nextCost) {
                    visited[nextNum][state|2] = nextCost;
                    pq.push({{nextCost, nextNum}, {curV1Flag, true}});
                }
            }else {
                if(visited[nextNum][state]>nextCost) {
                    visited[nextNum][state] = nextCost;
                    pq.push({{nextCost, nextNum}, {curV1Flag, curV2Flag}});
                }
            }
        }
    }

    cout << "-1";
}