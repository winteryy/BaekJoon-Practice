#include <iostream>
#include <vector>
#define MOD 1000003

using namespace std;
using Mat = vector<vector<long long> >;

int n, s, e, t;
Mat adjMatrix;

Mat multiplyMat(const Mat& l, const Mat& r) {
    int matSize = l.size();
    Mat result(matSize, vector<long long>(matSize, 0));
    
    for(int i=0; i<matSize; i++) {
        for(int j=0; j<matSize; j++) {
            for(int k=0; k<matSize; k++) {
                result[i][j] += l[i][k]*r[k][j];
            }
            result[i][j]%=MOD;
        }
    }

    return result;
}

Mat powMat(const Mat& l, int exp) {
    if(exp == 1) return l;

    Mat half = powMat(l, exp/2);
    Mat result = multiplyMat(half, half);

    if(exp%2==0) {
        return result;
    } else {
        return multiplyMat(result, l);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> e >> t;
    s--; e--;
    adjMatrix = Mat(5*n+1, vector<long long>(5*n+1));

    string row;
    for(int i=0; i<n; i++) {
        cin >> row;
        for(int j=0; j<n; j++) {
            int cost = row[j]-'0';
            if(cost>0) {
                adjMatrix[5*i+cost-1][5*j] = 1;
            }
        }
        for(int j=0; j<4; j++) {
            adjMatrix[5*i+j][5*i+j+1] = 1;
        }
    }

    Mat ans = powMat(adjMatrix, t);
    cout << ans[s*5][e*5];
}