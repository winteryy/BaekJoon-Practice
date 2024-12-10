#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, v;
    cin >> n;

    vector<vector<int> > dist(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> dist[i][j];
        }
    }


    vector<vector<bool> > need(n, vector<bool>(n, true));
    bool isValid = true;

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {    
                if(i!=j && i!=k && j!=k) {
                    if(dist[i][k]+dist[k][j]==dist[i][j]) {
                        need[i][j] = false;
                    } else if(dist[i][k]+dist[k][j]<dist[i][j]) {
                        cout << "-1";
                        return 0;
                    }
                }
            }
        }
    }

    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(need[i][j]) {
                sum+=dist[i][j];
            }
        }
    }

    cout << sum/2;
}