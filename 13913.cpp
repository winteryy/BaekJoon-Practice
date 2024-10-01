#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321 

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<bool> isVisited(100001, false);
    vector<int> prev(100001, -1);
    queue<pair<int, pair<int, int> > > q; //{cost, {position, prev}}

    q.push({0, {n, n}});

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        if(isVisited[cur.second.first]) continue;
        prev[cur.second.first] = cur.second.second;
        if(cur.second.first == k) {
            cout << cur.first << "\n";
            break;
        }
        isVisited[cur.second.first] = true;
        
        int nextPosition[3] = {cur.second.first*2, cur.second.first+1, cur.second.first-1};

        for(int next : nextPosition) {
            if(0<=next && 100000>=next) {
                q.push({cur.first+1, {next, cur.second.first}});
            }
        }
    }

    vector<int> route;
    int ind = k;
    while(true) {
        route.push_back(ind);
        if(ind==n) break;
        ind = prev[ind];
    }

    for(int i=route.size()-1; i>=0; i--) {
        cout << route[i] << " ";
    }
}   