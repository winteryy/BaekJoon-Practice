#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adjList(n+1, vector<int>());
    vector<int> inDegree(n+1, 0);
    vector<bool> isVisited(n+1, false);

    for(int i=0; i<m; i++) {
        int cnt, prev, follow;
        cin >> cnt >> prev;

        for(int j=0; j<cnt-1; j++) {
            cin >> follow;
            adjList[prev].push_back(follow);
            inDegree[follow]++;

            prev = follow;
        }
    }

    queue<int> q;
    queue<int> resultQ;

    while(true) {
        bool flag = false;

        for(int i=1; i<=n; i++) {
            if(!isVisited[i] && inDegree[i]==0) {
                q.push(i);
                flag = true;
            }
        }

        if(!flag) break;

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            if(isVisited[front]) continue;

            isVisited[front] = true;
            resultQ.push(front);

            for(auto vertex: adjList[front]) {
                if(inDegree[vertex]>0) inDegree[vertex]--;
            }
        }
    }

    if(resultQ.size()!=n) {
        cout << "0";
    }else {
        while(!resultQ.empty()) {
            cout << resultQ.front() << "\n";
            resultQ.pop();
        }
    }

}