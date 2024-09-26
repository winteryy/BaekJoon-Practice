#include <iostream>

using namespace std;

int n, m;
int curArr[9];

void dfs(int depth) { //base: 0, return when depth==m
    if(depth==m) {
        for(int i=1; i<=m; i++) {
            cout << curArr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=curArr[depth]+1; i<=n; i++) {
        curArr[depth+1] = i;
        dfs(depth+1);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;    

    dfs(0);
}