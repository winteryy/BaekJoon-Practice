#include <iostream>
#include <vector>

using namespace std;

int n, height = 1;
vector<int> ants;
vector<vector<pair<int, int> > > adjList;
vector<vector<pair<int, int> > > sparse;

void dfs(const int& cur, const int& prev) {
    sparse[cur][0].first = prev;
    for(auto& adj: adjList[cur]) {
        if(adj.first != prev) {
            sparse[adj.first][0].second = adj.second;
            dfs(adj.first, cur);
        }
    }
}

void initSparseTable() {
    dfs(1, 0);

    for(int i=1; i<=height; i++) {
        for(int j=1; j<=n; j++) {
            auto ancToTarget = sparse[sparse[j][i-1].first][i-1];
            sparse[j][i].first = ancToTarget.first;
            sparse[j][i].second = sparse[j][i-1].second + ancToTarget.second;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    ants = vector<int>(n+1);
    adjList = vector<vector<pair<int, int> > >(n+1);
    for(int i=1; i<=n; i++) {
        cin >> ants[i];
    }

    int a, b, c;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b >> c;

        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }

    int bit = 1;

    while(bit<n) {
        height++;
        bit <<= 1;
    }

    sparse = vector<vector<pair<int, int> > >(n+1, vector<pair<int, int> >(height+1));

    initSparseTable();

    for(int i=1; i<=n; i++) {
        int cur = i;
        int energy = ants[i];
        for(int j=height; j>=0; j--) {
            auto& target = sparse[cur][j];
            if(target.first != 0 && energy >= target.second) {
                energy -= target.second;
                cur = target.first;
            }
        }
        cout << cur << "\n";
    }
}