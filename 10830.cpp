#include <iostream>
#include <vector>
#define MOD 1000

using namespace std;

int n;

vector<vector<int> > multiMatrix(vector<vector<int> >& mat1, vector<vector<int> >& mat2) {
    vector<vector<int> > newMatrix(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                newMatrix[i][j] = (newMatrix[i][j] + (mat1[i][k] * mat2[k][j] % MOD)) % MOD;
            }
        }
    }

    return newMatrix;
}

vector<vector<int> > powerMatrix(vector<vector<int> >& baseMat, long long power) {
    if(power==1) {
        return baseMat;
    } else {
        vector<vector<int> > dividedMat = powerMatrix(baseMat, power/2);
        vector<vector<int> > resultMat = multiMatrix(dividedMat, dividedMat);
        if(power%2==0) {
            return resultMat;
        } else {
            return multiMatrix(resultMat, baseMat);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long power;
    cin >> n >> power;
    
    vector<vector<int> > mat(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int> > result = powerMatrix(mat, power);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << result[i][j]%MOD << " ";
        }

        cout << "\n";
    }

}