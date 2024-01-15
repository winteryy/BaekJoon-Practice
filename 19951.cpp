#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, a, b, k;
    cin >> n >> m;
    vector<int> soil(n+1, 0);
    vector<int> command(n+1, 0);

    for(int i=1; i<=n; i++) {
        cin >> soil[i];
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b >> k;

        command[b] = command[b]+k;
        command[a-1] = command[a-1]-k;
    }

    int h=0;
    for(int i=n; i>0; i--) {
        h += command[i];
        soil[i] += h;
    }

    for(int i=1; i<=n; i++) {
        cout << soil[i] << " ";
    }

}

