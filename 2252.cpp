#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<bool> isVisited(n+1, false);
    vector<int> inDegree(n+1, 0);
    vector<vector<int> > adjList(n+1, vector<int>());

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> q;

    while(true) {
        bool flag = false;
        for(int i=1; i<=n; i++) {
            if(inDegree[i]==0 && !isVisited[i]) {
                q.push(i);
                flag = true;
            }
        }

        if(!flag) break;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            isVisited[front] = true;
            cout << front << " ";
            for(auto vertex: adjList[front]) {
                if(inDegree[vertex]>0) inDegree[vertex]--;
            }
        }
    }

}