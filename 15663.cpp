#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m;
bool isConsumed[8] = { false };
int curArr[9];
int numArr[8];

set<vector<int> > ans;

void dfs(int depth) { //base: 0, return when depth==m
    if(depth==m) {
        vector<int> vec;
        for(int i=1; i<=m; i++) {
            vec.push_back(curArr[i]);
        }

        ans.insert(vec);
        return;
    }

    for(int i=0; i<n; i++) {
        if(isConsumed[i]==true) continue;
        curArr[depth+1] = numArr[i];
        isConsumed[i] = true;
        dfs(depth+1);
        isConsumed[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> numArr[i];
    }

    sort(numArr, numArr+n);
    dfs(0);
    
    for(auto vec: ans) {
        for(auto num: vec) {
            cout << num << " ";
        }
        cout << "\n";
    }
}