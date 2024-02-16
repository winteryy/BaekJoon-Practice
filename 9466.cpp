#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>

using namespace std;

vector<int> nodes;
vector<int> isVisited;

int dfs(int now) {
    int next = nodes[now];
    int cycleCnt = 0;

    if(isVisited[next] == 0) {
        isVisited[next] = isVisited[now] + 1;
        cycleCnt = dfs(next);
    }else {
        cycleCnt = isVisited[now] - isVisited[next] + 1;
    }

    isVisited[now] = 100001;
    return cycleCnt<0 ? 0 : cycleCnt;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> n;
        
        nodes = vector<int>(n+1);
        isVisited = vector<int>(n+1, 0);

        for(int j=1; j<=n; j++) {
            cin >> nodes[j];
            isVisited[j] = 0;
        }
        
        int cnt = 0;

        for(int j=1; j<=n; j++) {
            if(isVisited[j] == 0) {
                isVisited[j] = 1;
                cnt += dfs(j);
            }
        }

        cout << n-cnt << "\n";

    }

}

