#include <iostream>
#include <vector>

using namespace std;

int main() {

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<long> > matrix(n+2, vector<long>(n+2, 0)); 
    vector<vector<long> > accMatrix(n+2, vector<long>(n+2, 0)); 

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            accMatrix[i][j] = accMatrix[i-1][j] + accMatrix[i][j-1] - accMatrix[i-1][j-1] + matrix[i][j];
        }
    }

    vector<long> answers;
    int x1, x2, y1, y2;
    long result;
    for(int i=0; i<m; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        result = accMatrix[y2][x2] - accMatrix[y1-1][x2] + accMatrix[y1-1][x1-1] - accMatrix[y2][x1-1];
        answers.push_back(result);
    }

    for(auto num: answers) {
        cout << num << "\n";
    }
}