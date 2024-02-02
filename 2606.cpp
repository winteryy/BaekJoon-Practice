#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int v, e;
    cin >> v >> e;

    vector<vector<int> > matrix(v+1);

    for(int i=0; i<e; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        matrix[v1].push_back(v2);
        matrix[v2].push_back(v1);
    }

    int cnt = 0;
    vector<bool> isVisited(v+1, false);
    stack<int> st;
    st.push(1);

    while(!st.empty()) {
        int cur = st.top();
        st.pop();

        if(isVisited[cur]) continue;

        isVisited[cur] = true;
        cnt++;
        for(auto adj: matrix[cur]) {
            if(!isVisited[adj]) {
                st.push(adj);
            }
        }
    }

    cout << cnt-1;
} 