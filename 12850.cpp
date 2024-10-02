#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

vector<vector<long long> > squareMatrix(vector<vector<long long> >& mat1, vector<vector<long long> >& mat2) {
    vector<vector<long long> > newMatrix(8, vector<long long>(8, 0));

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            for(int k=0; k<8; k++) {
                newMatrix[i][j] = (newMatrix[i][j] + (mat1[i][k] * mat2[k][j]) % MOD) % MOD;
            }
        }
    }

    return newMatrix;
}

vector<vector<long long> > power(int n, vector<vector<long long> >& mat) {
    if(n==1) return mat;

    vector<vector<long long> > dividedMatrix = power(n/2, mat);
    vector<vector<long long> > newMatrix = squareMatrix(dividedMatrix, dividedMatrix);
    if(n%2==0) {
        return newMatrix;
    }else {
        return squareMatrix(newMatrix, mat);
    }
}

int main() {
    int d;
    cin >> d;

    //{ 정보과학관, 전산관, 신양관, 미래관, 진리관, 한경직기념관, 학생회관, 형남공학관 }
    vector<vector<long long> > adjMatrix = {
        { 0, 1, 0, 1, 0, 0, 0, 0 },
        { 1, 0, 1, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 1, 1, 0, 0 },
        { 1, 1, 1, 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0, 1, 1, 0 },
        { 0, 0, 1, 1, 1, 0, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 0 },
    };

    vector<vector<long long> > result = power(d, adjMatrix);
    cout << result[0][0];
}