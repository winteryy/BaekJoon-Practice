#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<int> > adjList;
vector<bool> isVisited;
vector<vector<int> > dp; //{{isEarlyAdpt, isNotEarlyAdpt}}

void traversal(int n) {
    isVisited[n] = true;
    dp[n][0] = 1;

    for(int adj: adjList[n]) {
        if(!isVisited[adj]) {
            traversal(adj);
            dp[n][1]+=dp[adj][0];
            dp[n][0]+=min(dp[adj][0], dp[adj][1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int node1, node2;

    adjList = vector<vector<int> >(n+1, vector<int>());
    isVisited = vector<bool>(n+1, false);
    dp = vector<vector<int> >(n+1, vector<int>(2, 0));

    for(int i=0; i<n-1; i++) {
        cin >> node1 >> node2;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    traversal(1);

    cout << (dp[1][0]<dp[1][1] ? dp[1][0] : dp[1][1]);
}