#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tc, n, m, w, s, e, t;

    cin >> tc;

    for(int i=0; i<tc; i++) {
        cin >> n >> m >> w;
        vector<vector<int> > edgeMatrix(n+1, vector<int>(n+1, INF)); //cost matrix

        //init
        for(int j=0; j<m; j++) { 
            cin >> s >> e >> t;

            edgeMatrix[s][e] = min(edgeMatrix[s][e], t);
            edgeMatrix[e][s] = min(edgeMatrix[e][s], t);
        }

        for(int j=0; j<w; j++) {
            cin >> s >> e >> t;

            edgeMatrix[s][e] = min(edgeMatrix[s][e], -t);
        }

        bool hasNegativeCycle = false;
        vector<bool> isDirty(n+1, false);
        //시작점 특정x, 모든 vertex 확인
        for(int j=1; j<=n; j++) {
            //BellmanFord
            if(isDirty[j]) continue;

            vector<int> dist(n+1, INF);
            dist[j] = 0;
            queue<int>* q = new queue<int>(); //갱신 vertex
            q->push(j);

            for(int k=0; k<n; k++) {
                queue<int>* newQ = new queue<int>();
                while(!q->empty()) {
                    int cur = q->front();
                    q->pop();

                    isDirty[cur] = true;

                    for(int l=1; l<=n; l++) {
                        if(edgeMatrix[cur][l]!=INF && dist[cur]+edgeMatrix[cur][l]<dist[l]) {
                            dist[l] = dist[cur]+edgeMatrix[cur][l];
                            newQ->push(l);  
                        }
                    }
                }

                delete q;
                q = newQ;
            }

            //negative cycle 확인
            if(!q->empty()) {
                hasNegativeCycle = true;
                break;
            }
        }

        cout << (hasNegativeCycle ? "YES" : "NO") << "\n";
    }
}