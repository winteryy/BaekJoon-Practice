#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int v, e, id = 0, sccInd = 0;
vector<vector<int> > adjList;
vector<bool> isFinished;
vector<int> parentNum;
stack<int> st;
vector<int> sccNums;

int dfs(int x) {
    parentNum[x] = ++id;
    st.push(x);
    
    int parent = parentNum[x];
    for(int adj: adjList[x]) {
        if(parentNum[adj] == 0) { // 规巩 捞仿 x
            parent = min(parent, dfs(adj));
        } else if(!isFinished[adj]) { // 规巩 o, scc 贸府 x
            parent = min(parent, parentNum[adj]);
        }
    }

    if(parent == parentNum[x]) {
        sccInd++;
        while(true) {
            int cur = st.top();
            st.pop();

            sccNums[cur] = sccInd;
            isFinished[cur] = true;
            if(cur == x) break;
        }
    }

    return parent;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> v >> e;
    
    adjList = vector<vector<int> >(v+1);
    for(int i=0; i<e; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
    }

    parentNum = vector<int>(v+1, 0);
    isFinished = vector<bool>(v+1, false);
    sccNums = vector<int>(v+1, 0);

    for(int i=1; i<=v; i++) {
        if(parentNum[i]==0) {
            dfs(i);
        }
    }

    vector<int> sccNumToInd(sccInd+1, 0);
    vector<vector<int> > result(1);

    for(int i=1; i<=v; i++) {
        int ind = sccNumToInd[sccNums[i]];
        if(ind==0) {
            ind = sccNumToInd[sccNums[i]] = result.size();
            result.push_back(vector<int>());
        }
        result[ind].push_back(i);
    }

    cout << sccInd << "\n";

    for(int i=1; i<=sccInd; i++) {
        for(int num: result[i]) {
            cout << num << " ";
        }
        cout << "-1\n";
    }
}