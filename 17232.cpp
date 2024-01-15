#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, t;
    int k, a, b;

    cin >> n >> m >> t;
    cin >> k >> a >> b;

    vector<vector<bool> > matrix(n+2, vector<bool>(m+2, false));
    vector<vector<int> > accMatrix(n+2, vector<int>(m+2, 0));
    char c;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> c;
            if(c=='*') {
                matrix[i][j] = true;
            }
        }
    }

    for(int g=0; g<t; g++) {
        accMatrix = vector<vector<int> >(n+2, vector<int>(m+2, 0));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                accMatrix[i][j] = accMatrix[i-1][j] + accMatrix[i][j-1] - accMatrix[i-1][j-1];
                if(matrix[i][j]) {
                    accMatrix[i][j]++;
                }
            }
        }
        int x1, x2, y1, y2, value;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                x1 = (j-k<1 ? 1 : j-k);
                x2 = (j+k>m ? m : j+k);
                y1 = (i-k<1 ? 1 : i-k);
                y2 = (i+k>n ? n : i+k);

                value = accMatrix[y2][x2] - accMatrix[y1-1][x2] - accMatrix[y2][x1-1] + accMatrix[y1-1][x1-1];
                if(matrix[i][j]) {
                    value -= 1;
                    if(value<a || value>b) {
                        matrix[i][j] = false;
                    }
                }else if(value>a && value<=b) {
                    matrix[i][j] = true;
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if(matrix[i][j]){
                cout << "*";
            }else{
                cout << ".";
            }
        }
        cout << "\n";
    }
}