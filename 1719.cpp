#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > dist(n+1, vector<int>(n+1, INF)); 
    vector<vector<string> > answer(n+1, vector<string>(n+1, ""));

    for(int i=1; i<=n; i++) dist[i][i] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            answer[i][j] = to_string(j);
        }
    }
    int orig, dest, cost;
    while(m--) {
        cin >> orig >> dest >> cost;
        dist[dest][orig] = dist[orig][dest] = min(dist[orig][dest], cost);
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int newDist = dist[i][k] + dist[k][j];
                if(dist[i][j]>newDist) {
                    dist[i][j] = newDist;
                    answer[i][j] = answer[i][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) {
                answer[i][j] = "-";
            }
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}