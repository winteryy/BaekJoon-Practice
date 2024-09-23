#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root[30001];

int find(int x) {
    if(x == root[x]) {
        return x;
    } else {
        return root[x] = find(root[x]);
    }
}

void makeUnion(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if(rootX == rootY) return;
    if(rootX < rootY) {
        root[rootY] = rootX;
    } else {
        root[rootX] = rootY;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> candyList(n+1);

    for(int i=1; i<=n; i++) {
        cin >> candyList[i];
        root[i] = i;
    }

    int child1, child2;
    for(int i=0; i<m; i++) {
        cin >> child1 >> child2;
        makeUnion(child1, child2);
    }

    vector<pair<int, int> > childUnionList; // { candySum, childNum }
    vector<int> candySum(n+1, 0);
    vector<int> childCount(n+1, 0);

    for(int i=1; i<=n; i++) {
        int unionNum = find(i);
        candySum[unionNum] += candyList[i];
        childCount[unionNum]++;
    }
    for(int i=1; i<=n; i++) {
        if(childCount[i]>0) {
            childUnionList.push_back({candySum[i], childCount[i]});
        }
    }

    vector<vector<int> > dp(childUnionList.size()+1, vector<int>(k, 0));

    for(int i=1; i<=childUnionList.size(); i++) {
        for(int j=1; j<k; j++) {
            if(childUnionList[i-1].second <= j) {
                dp[i][j] = max(childUnionList[i-1].first+dp[i-1][j-childUnionList[i-1].second], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[childUnionList.size()][k-1];
}