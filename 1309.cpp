#include <iostream>
#include <vector>
#define MOD_NUM 9901

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > fence(2, vector<int>(n, 0)); //col 0: non-empty 1: empty

    fence[0][0] = 2;
    fence[1][0] = 1;

    for(int i=1; i<n; i++) {
        fence[0][i] += (fence[0][i-1] + fence[1][i-1]*2) % MOD_NUM;
        fence[1][i] += (fence[0][i-1] + fence[1][i-1]) % MOD_NUM;
    }

    cout << (fence[0][n-1] + fence[1][n-1]) % MOD_NUM;
}