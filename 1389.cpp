#include <iostream>
#include <vector>
#include <algorithm>
#define INF 5000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > dist(n+1, vector<int>(n+1, INF));

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for(int i=1; i<=n; i++) {
        dist[i][i] = 0;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    int ans = 1;
    int kevin = INF;

    for(int i=1; i<=n; i++) {
        int sum = 0;
        for(int j=1; j<=n; j++) {
            sum+=dist[i][j];
        }
        if(kevin>sum) {
            ans = i;
            kevin = sum;
        }
    }

    cout << ans;
}