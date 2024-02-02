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

    stack<int> st;
    vector<bool> isVisited(v+1, false);
    int cnt = 0;
    for(int i=1; i<=v; i++) {
        if(!isVisited[i]) {
            cnt++;
            st.push(i);

            while(!st.empty()) {
                int cur = st.top();
                st.pop();
                if(isVisited[cur]) continue;
                isVisited[cur] = true;

                for(auto adj: matrix[cur]) {
                    if(!isVisited[adj]) {
                        st.push(adj);
                    }
                }

            }
        }
    }

    cout << cnt;
    
}