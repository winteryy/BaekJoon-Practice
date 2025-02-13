#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

int n, m;
vector<unordered_set<int> > cnfGraph;
vector<unordered_set<int> > revCnfGraph;
vector<bool> isVisited;
vector<int> scc;
vector<vector<int> > sccList;
stack<int> st;
int sccInd = 0;

void dfs(const int& cur) {
    if(isVisited[cur]) return;
    isVisited[cur] = true;
    for(auto& adj: cnfGraph[cur]) {
        if(!isVisited[adj]) {
            dfs(adj);
        }
    }
    st.push(cur);
}

void revDfs(const int& cur) {
    if(isVisited[cur]) return;
    isVisited[cur] = true;
    scc[cur] = sccInd;
    sccList[sccInd].push_back(cur);
    for(auto& adj: revCnfGraph[cur]) {
        if(!isVisited[adj]) {
            revDfs(adj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cnfGraph = vector<unordered_set<int> >(n*2+1);
    revCnfGraph = vector<unordered_set<int> >(n*2+1);
    isVisited = vector<bool>(n*2+1, false);
    scc = vector<int>(n*2+1);
    sccList = vector<vector<int> >(n*2+1);

    int u, v;
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        cnfGraph[n-u].insert(n+v);
        cnfGraph[n-v].insert(n+u);
        revCnfGraph[n+u].insert(n-v);
        revCnfGraph[n+v].insert(n-u);
    }

    for(int i=0; i<n; i++) {
        dfs(i);
    }
    for(int i=n+1; i<=n*2; i++) {
        dfs(i);
    }

    fill(isVisited.begin(), isVisited.end(), false);

    while(!st.empty()) {
        int cur = st.top();
        st.pop();

        if(!isVisited[cur]) {
            sccInd++;
            revDfs(cur);
        }
    }

    for(int i=1; i<=n; i++) {
        if(scc[n-i]==scc[n+i]) {
            cout << "0\n";
            return 0;
        }
    }
    
    cout << "1\n";
    vector<bool> ans(n*2+1, false);
    for(int i=sccInd; i>=1; i--) {
        for(auto& node: sccList[i]) {
            if(ans[node]) continue;
            ans[node] = false;
            ans[n+n-node] = true;
        }
    }

    for(int i=n-1; i>=0; i--) {
        cout << ans[i] << " ";
    }
}