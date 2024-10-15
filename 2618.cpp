#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, w;
vector<pair<int, int> > incidentList;
vector<vector<int> > dp;
vector<vector<int> > prevList;

int getDist(pair<int, int>& p1, pair<int, int>& p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int solve(int a, int b) {
    
    if(a==w+1 || b==w+1) dp[a][b] = 0;
    if(dp[a][b]!=-1) return dp[a][b];
    
    int nextIncident = max(a, b) + 1;
    int dist1 = solve(nextIncident, b) + getDist(incidentList[a], incidentList[nextIncident]); //경찰차1이 해결
    int dist2 = solve(a, nextIncident) + getDist(incidentList[b], incidentList[nextIncident]); //경찰차2가 해결

    if(dist1<dist2) {
        prevList[a][b] = 1;
        dp[a][b] = dist1;
    } else {
        prevList[a][b] = 2;
        dp[a][b] = dist2;
    }

    return dp[a][b];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> w;
    
    int r, c;
    incidentList = vector<pair<int, int> >(w+2);
    for(int i=2; i<=w+1; i++) {
        cin >> r >> c;
        incidentList[i] = {r, c};
    }
    incidentList[0] = {1, 1};
    incidentList[1] = {n, n};

    dp = vector<vector<int> >(w+2, vector<int>(w+2, -1)); // [1번 경찰차][2번 경찰차]
    prevList = vector<vector<int> >(w+2, vector<int>(w+2, -1));

    cout << solve(0, 1) << "\n";

    int carInd1 = 0;
    int carInd2 = 1;
    
    while(carInd1<w+1 && carInd2<w+1) {
        cout << prevList[carInd1][carInd2] << "\n";
        if(prevList[carInd1][carInd2]==1) {
            carInd1 = max(carInd1, carInd2) + 1;
        } else {
            carInd2 = max(carInd1, carInd2) + 1;
        }
    }
}