#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, orig, dest;
    cin >> n >> orig >> dest >> m;

    vector<vector<int> > adjList(n+1);

    int x, y;
    while(m--) {
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    vector<bool> isVisited(n+1, false);
    stack<pair<int, int> > st;
    st.push({orig, 0});

    while(!st.empty()) {
        int cur = st.top().first;
        int depth = st.top().second;
        st.pop();
        
        if(cur==dest) {
            cout << depth;
            return 0;
        }
        isVisited[cur] = true;

        for(int adj : adjList[cur]) {
            if(!isVisited[adj]) {
                st.push({adj, depth+1});
            }
        }
    }

    cout << -1;
}