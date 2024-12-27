#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > dp; //0: 일반 마을, 1: 우수 마을
vector<int> residents;
vector<vector<int> > adjList;
vector<bool> isVisited;

void dfs(int num) {
    if(isVisited[num]) return;

    isVisited[num] = true;
    dp[num][0] = 0;
    dp[num][1] = residents[num];

    for(auto next: adjList[num]) {
        if(isVisited[next]) continue;

        dfs(next);

        dp[num][0] += max(dp[next][0], dp[next][1]);
        dp[num][1] += dp[next][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    dp = vector<vector<int> >(n+1, vector<int>(2, 0));
    residents = vector<int>(n+1);
    isVisited = vector<bool>(n+1, false);
    adjList = vector<vector<int> >(n+1);

    for(int i=1; i<=n; i++) {
        cin >> residents[i];
    }

    int a, b;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}