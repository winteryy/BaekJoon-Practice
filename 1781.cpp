#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<pair<int, int> > > adjList; //{node, cost}
pair<int, long long> ancestors[40001][17]; //[node][k]{num, costSum}
int depthList[40001];

void dfs(int n, int depth) {

    depthList[n] = depth;
    
    if(n!=1) {
        int ind = 1, indDepth = 2;
        int anc = ancestors[n][0].first;
        long long costSum = ancestors[n][0].second;

        while(indDepth<=depth) {
            costSum += ancestors[anc][ind-1].second;
            ancestors[n][ind] = {ancestors[anc][ind-1].first, costSum};
            anc = ancestors[anc][ind-1].first;
            ind++;
            indDepth*=2;
        }
    }
    
    for(auto adj: adjList[n]) {
        if(adj.first != ancestors[n][0].first) { //부모노드 아니면
            ancestors[adj.first][0] = {n, adj.second};
            dfs(adj.first, depth+1);
        }
    }
}

long long lcaSum(int a, int b) {
    if(depthList[a]<depthList[b]) {
        swap(a, b);
    }
    int k = 0;
    while(1<<(k+1) <= depthList[a]) k++;

    long long costSum = 0;
    for(int i=k; i>=0; i--) {
        if(depthList[a] - (1<<i) >= depthList[b]) {
            costSum += ancestors[a][i].second;
            a = ancestors[a][i].first;
        }
    }

    if(a==b) return costSum;

    for(int i=k; i>=0; i--) {
        if(ancestors[a][i].first!=0 && ancestors[a][i].first!=ancestors[b][i].first) {
            costSum += ancestors[a][i].second;
            costSum += ancestors[b][i].second;

            a = ancestors[a][i].first;
            b = ancestors[b][i].first;
        }
    }

    costSum += ancestors[a][0].second;
    costSum += ancestors[b][0].second;

    return costSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    adjList = vector<vector<pair<int, int> > >(n+1);

    int a, b, cost;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b >> cost;
        adjList[a].push_back({b, cost});
        adjList[b].push_back({a, cost});
    }

    dfs(1, 0);

    int m;
    cin >> m;

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        cout << lcaSum(a, b) << "\n";
    }
}