#include <iostream>

using namespace std;

bool adjMatrix[100][100] = {false, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==k || j==k) continue;

                if(adjMatrix[i][j]||(adjMatrix[i][k] && adjMatrix[k][j])) {
                    adjMatrix[i][j] = true;
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}