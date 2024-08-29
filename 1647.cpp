#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int> > edge;

int root[100000];

int find(int n) {
    if(root[n]==n) {
        return n;
    } else {
        root[n] = find(root[n]);
        return root[n];
    }
}

bool makeUnion(int x, int y) {
    x = find(x);
    y = find(y);

    if(x<y) {
        root[y] = x;
        return true;
    } else if(x>y) {
        root[x] = y;
        return true;
    } else {
        return false;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m, start, end, cost;
    cin >> n >> m;

    priority_queue<edge> pq;

    for(int i=0; i<n; i++) {
        root[i] = i;
    }

    for(int i=0; i<m; i++) {
        cin >> start >> end >> cost;
        pq.push({-cost, {start, end}});
    }

    int minCost = 0;
    int unionNum = n;

    while(!pq.empty() && unionNum > 2) {
        edge e = pq.top();
        pq.pop();

        if(makeUnion(e.second.first, e.second.second)) {
            unionNum--;
            minCost-=e.first;
        }
    }

    cout << minCost;
}