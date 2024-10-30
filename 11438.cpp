#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ancestor[100001][17];
int depthList[100001];
vector<vector<int> > adjList;

void dfs(int n, int depth) {

    depthList[n] = depth;

    for(int i=1; i<17; i++) {
        if(depth - (1<<i) >= 0) {
            ancestor[n][i] = ancestor[ancestor[n][i-1]][i-1];
        } else {
            break;
        }
    }

    for(int adj: adjList[n]) {
        if(adj != ancestor[n][0]) {
            ancestor[adj][0] = n;
            dfs(adj, depth+1);
        }
    }
}

int lca(int a, int b) {
    if(depthList[a]<depthList[b]) swap(a, b);

    int k = 0;
    while(1<<(k+1) <= depthList[a]) k++;

    for(int i=k; i>=0; i--) {
        if(depthList[a]-(1<<i) >= depthList[b]) {
            a = ancestor[a][i];
        }
    }

    if(a==b) return a;

    for(int i=k; i>=0; i--) {
        if(ancestor[a][i]!=0 && ancestor[a][i] != ancestor[b][i]) {
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }

    return ancestor[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, a, b;

    cin >> n;
    adjList = vector<vector<int> >(n+1);

    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1, 0);

    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}