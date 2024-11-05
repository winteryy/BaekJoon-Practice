#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int t, n, d;

vector<vector<int> > multiMatrix(vector<vector<int> >& a, vector<vector<int> >& b) {
    vector<vector<int> > result(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n ; i++) {
        for(int j=1; j<=n; j++) {
            long long sum = 0;
            for(int k=1; k<=n; k++) {
                sum += ((long long)a[i][k]%MOD * (long long)b[k][j]%MOD) % MOD;
                sum %= MOD;
            }
            result[i][j] = sum;
        }
    }

    return result;
}

vector<vector<int> > powerMatrix(vector<vector<int> >& mat, int exp) {
    if(exp==1) return mat;

    vector<vector<int> > half = powerMatrix(mat, exp/2);
    vector<vector<int> > result = multiMatrix(half, half);
    if(exp%2 == 0) {
        return result;
    } else {
        return multiMatrix(result, mat);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> n >> d;

    vector<vector<int> > all(n+1, vector<int>(n+1, 0));
    vector<vector<int> > result(n+1, vector<int>(n+1, 0));
    vector<vector<int> > remain(n+1, vector<int>(n+1, 1));

    for(int i=1; i<=n; i++) {
        all[i][i] = 1;
        result[i][i] = 1;
    }

    for(int i=0; i<t; i++) {
        int m, a, b, c;
        cin >> m;

        vector<vector<int> > temp(n+1, vector<int>(n+1, 0));

        for(int j=0; j<m; j++) {
            cin >> a >> b >> c;
            temp[a][b] = c;
        }

        if(d%t == i) {
            remain = all;
        }
        all = multiMatrix(all, temp);
    }

    if(d/t != 0) {
        result = powerMatrix(all, d/t);
    }

    result = multiMatrix(result, remain);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}