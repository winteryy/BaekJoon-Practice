#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> root;

int find(int n) {
    if(root[n]==n) return n;

    return root[n]=find(root[n]);
}

bool makeUnion(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if(rootX==rootY) {
        return false;
    } else if(rootX<rootY) {
        root[rootY] = rootX;
    } else {
        root[rootX] = rootY;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b, c;
    cin >> n >> m;

    for(int i=0; i<=n; i++) {
        root.push_back(i);
    }

    auto cmp = [](const pair<pair<int, int>, int>& l, const pair<pair<int, int>, int>& r) {
        return l.second>r.second;
    };
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >, decltype(cmp)> pq(cmp);

    while(m--) {
        cin >> a >> b >> c;

        if(a!=b) pq.push({{a, b}, c});
    }

    int edgeNum = 0;
    int costSum = 0;
    while(edgeNum<n-1) {
        auto nodeP = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(makeUnion(nodeP.first, nodeP.second)) {
            edgeNum++;
            costSum += cost;
        }
    }

    cout << costSum;
}