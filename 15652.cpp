#include <iostream>

using namespace std;

int n, m;
int arr[9];

void dfs(int num, int depth) {
    if(depth == m) {
        for(int i=1; i<m; i++) {
            cout << arr[i] << " ";
        }
        cout << num << "\n";
        return;
    } else {
        arr[depth] = num;
        for(int i=num; i<=n; i++) {
            dfs(i, depth+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> m;
    dfs(1, 0);
}