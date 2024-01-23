#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int n;
vector<vector<int> > costMatrix;
vector<vector<int> > dp;

int DFS(int cur, int visit) {
    if(visit == (1<<n)-1) {
        if(costMatrix[cur][0]==0) {
            return INF;
        }
        return costMatrix[cur][0];
    }

    if(dp[cur][visit] != -1) {
        return dp[cur][visit];
    }

    dp[cur][visit] = INF;

    for(int i=0; i<n; i++) {
        if(costMatrix[cur][i]==0) {
            continue;
        }
        if((visit & (1<<i)) == (1<<i)) {
            continue;
        }
        dp[cur][visit] = min(dp[cur][visit], costMatrix[cur][i]+DFS(i, visit | 1<<i));
    }

    return dp[cur][visit];
}

int main() {

    cin >> n;

    costMatrix = vector<vector<int>>(n, vector<int>(n));
    dp = vector<vector<int> >(n, vector<int>(1<<n, -1));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> costMatrix[i][j];
        }
    }

    cout << DFS(0, 1);

}