#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

int n, m;
vector<unordered_set<int> > cnfGraph;
vector<unordered_set<int> > revCnfGraph; 
stack<int> st;
vector<bool> isVisited;
vector<int> scc;
int sccInd = 0;

void dfs(int x) {
    if(isVisited[x]) return;
    isVisited[x] = true;
    for(int adj: cnfGraph[x]) {
        if(!isVisited[adj]) {
            dfs(adj);
        }
    }
    st.push(x);
}

void reDfs(int x) {
    if(isVisited[x]) return;
    isVisited[x] = true;
    scc[x] = sccInd;
    for(int adj: revCnfGraph[x]) {
        if(!isVisited[adj]) {
            reDfs(adj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cnfGraph = vector<unordered_set<int> >(2*n+1);
    revCnfGraph = vector<unordered_set<int> >(2*n+1);
    isVisited = vector<bool>(n*2+1, false);
    scc = vector<int>(n*2+1);

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        cnfGraph[n-u].insert(v+n);
        cnfGraph[n-v].insert(u+n);
        revCnfGraph[v+n].insert(n-u);
        revCnfGraph[u+n].insert(n-v);
    }

    for(int i=0; i<n; i++) {
        dfs(i);
    }
    for(int i=n+1; i<=n*2; i++) {
        dfs(i);
    }

    isVisited = vector<bool>(n*2+1, false);

    while(!st.empty()) {
        auto cur = st.top();
        st.pop(); 
        if(!isVisited[cur]) {
            sccInd++;
            reDfs(cur);
        }
    }

    for(int i=1; i<=n; i++) {
        if(scc[n-i] == scc[n+i]) {
            cout << "0";
            return 0;
        }   
    }

    cout << "1";
}