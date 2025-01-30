#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int curArr[8];
bool isVisited[9];

void dfs(int depth) {
    if(depth == m) {
        for(int i=0; i<m; i++) {
            cout << curArr[i] << " ";
        }
        cout << "\n";
    }

    for(int i=1; i<=n; i++) {   
        if(isVisited[i]==false) {
            isVisited[i] = true;
            curArr[depth] = i;
            dfs(depth+1);
            isVisited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    memset(isVisited, false,  n+1);
    dfs(0);
}