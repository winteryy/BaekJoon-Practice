#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long> > pascal;

long long comb(int n, int r) {
    if(r==0 || n==r) {
        return 1;
    }
    
    if(pascal[n][r] == 0) {
        pascal[n][r] = comb(n-1, r-1) + comb(n-1, r);
    }

    return pascal[n][r];
}

int main() {
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        pascal = vector<vector<long long> > (m+1, vector<long long>(m+1, 0));
        cout << comb(m, n) << "\n";        
    }
}