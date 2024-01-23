#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int n;
vector<vector<int> > costMatrix;
vector<vector<int> > dp;

int TSP(int curV, int visitMask) {

    if(visitMask == (1<<n)-1) { //모든 정점 방문
        if(costMatrix[curV][0]==0) {
            return INF;
        }
        return costMatrix[curV][0];
    }

    if(dp[curV][visitMask] != -1) { //이미 방문함
        return dp[curV][visitMask];
    }

    dp[curV][visitMask] = INF;

    for(int i=0; i<n; i++) {
        if(costMatrix[curV][i]==0) { //간선 연결 체크
            continue;
        }
        if((visitMask & (1<<i)) == (1<<i)) { //다음 정점이 방문한 곳
            continue;
        }
        dp[curV][visitMask] = min(dp[curV][visitMask], costMatrix[curV][i]+TSP(i, visitMask | 1<<i)); 
    }

    return dp[curV][visitMask];
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

    cout << TSP(0, 1);

}