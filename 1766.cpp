#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adjList(n+1, vector<int>());
    vector<int> inDegree(n+1, 0);
    vector<bool> isVisited(n+1, false);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        inDegree[b]++;
    }

    priority_queue<int> pq;

    for(int i=1; i<=n; i++) {
        if(inDegree[i]==0) {
            pq.push(-i);
            isVisited[i] = true;
        }
    }

    while(!pq.empty()) {
        int top = -pq.top();
        pq.pop();
        cout << top << " ";

        for(auto vertex: adjList[top]) {
            if(inDegree[vertex]>0) inDegree[vertex]--;
            if(inDegree[vertex]==0&&!isVisited[vertex]) {
                pq.push(-vertex);
                isVisited[vertex]=true;
            }
        }

    }
}