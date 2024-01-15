#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef long long LL;

vector<vector<LL> > matrixMultiplication(vector<vector<LL> > l, vector<vector<LL> > r) {
    vector<vector<LL> > result(2, vector<LL>(2, 0));

    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            result[i][j] = (l[i][0]*r[0][j] % MOD) + (l[i][1]*r[1][j] % MOD);
            result[i][j] %= MOD;
        }
    }

    return result;
}

vector<vector<LL> > matrixPow(vector<vector<LL> > m, LL n) {
    if(n==1) {
        return m;
    }
    if(n%2==1) {
        return matrixMultiplication(m, matrixPow(m, n-1));
    }
    vector<vector<LL> > half = matrixPow(m, n/2);
    return matrixMultiplication(half, half);
}

int main() {
    LL n;
    cin >> n;

    vector<vector<LL> > originMatrix = {{1, 1}, {1, 0}};
    vector<vector<LL> > result;
    result = matrixPow(originMatrix, n);
    cout << result[1][0];

}