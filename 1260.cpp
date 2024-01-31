#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int v, e, start;
    cin >> v >> e >> start;

    vector<vector<bool> > matrix(v+1, vector<bool>(v+1, false));

    for(int i=0; i<e; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        matrix[v1][v2] = true;
        matrix[v2][v1] = true;
    }

    vector<bool> isVisited(v+1, false);
    stack<int> st;
    st.push(start);

    while(!st.empty()) {
        int cur = st.top();
        st.pop();
        if(isVisited[cur]) continue;
        isVisited[cur] = true;
        cout << cur << " ";

        for(int i=v; i>=1; i--) {
            if(matrix[cur][i]&&!isVisited[i]) {
                st.push(i);
            }
        }
    }

    cout << "\n";

    isVisited = vector<bool>(v+1, false);
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(isVisited[cur]) continue;
        isVisited[cur] = true;
        cout << cur << " ";

        for(int i=1; i<=v; i++) {
            if(matrix[cur][i]&&!isVisited[i]) {
                q.push(i);
            }
        }
    }
}