#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define DIST_INF 987654321

using namespace std;

typedef vector<vector<pair<int, int> > > vvpii;

int n, m;
int s, e, l;
vvpii adjList;
vector<vector<int> > dist;

void floyd() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dist[i][j] = adjList[i][j].first;
        }
        dist[i][i] = 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

double calcBurnTime() {
    double minBurnTime = 2000000.0;

    for(int i=1; i<=n; i++) { // 점화 노드
        double localMax = 0.0;
        for(int j=1; j<=n; j++) {
            for(int k=j; k<=n; k++) {
                if(adjList[j][k].second == 0) continue;
                
                int nearNode = min(dist[i][j], dist[i][k]);
                int diff = abs(dist[i][j]-dist[i][k]);
                localMax = max(localMax, nearNode+diff+(adjList[j][k].second - diff)/2.0);
            }
        }
        minBurnTime = min(minBurnTime, localMax);
    }

    return minBurnTime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adjList = vvpii(n+1, vector<pair<int, int> >(n+1, {DIST_INF, 0})); // [s][d]{min, max}

    for(int i=0; i<m; i++) {
        cin >> s >> e >> l;
        
        adjList[s][e].first = min(adjList[s][e].first, l);
        adjList[s][e].second = max(adjList[s][e].second, l);
        adjList[e][s].first = min(adjList[e][s].first, l);
        adjList[e][s].second = max(adjList[e][s].second, l);
    }

    dist = vector<vector<int> >(n+1, vector<int>(n+1, DIST_INF));
    floyd();
    
    cout << fixed;
    cout << setprecision(1);
    cout << calcBurnTime();
}