#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int T, n, k, target;
    cin >> T;

    for(int t=0; t<T; t++) {
        cin >> n >> k;

        vector<vector<int> > adjList(n+1, vector<int>());
        vector<pair<int, int> > inDegree(n+1, {0, 0});
        vector<int> timeTake(n+1);
        vector<bool> isVisited(n+1, false);


        for(int i=1; i<=n; i++) {
            cin >> timeTake[i];
        }

        for(int i=0; i<k; i++) {
            int a, b;
            cin >> a >> b;

            adjList[a].push_back(b);
            inDegree[b].first++;
        }

        cin >> target;

        int time = 0;

        queue<int> q;
        bool getGoalFlag = false;

        while(true) {
            bool flag = false;

            for(int i=1; i<=n; i++) {
                if(inDegree[i].first==0 && !isVisited[i]) {
                    q.push(i);
                    flag = true;
                } 
            }

            if(!flag) break;

            while(!q.empty()) {
                int front = q.front();
                q.pop();

                if(front == target) {
                    cout << inDegree[front].second+timeTake[front] << "\n";
                    getGoalFlag = true;
                    break;
                }

                isVisited[front] = true;

                for(auto vertex : adjList[front]) {
                    if(inDegree[vertex].first>0) inDegree[vertex].first--;
                    inDegree[vertex].second = max(inDegree[vertex].second, inDegree[front].second+timeTake[front]);
                }
            }

            if(getGoalFlag) break;
        }
    }

}