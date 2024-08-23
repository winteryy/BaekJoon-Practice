#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> matrix;

int main() {
    int n, r, c;
    cin >> n;

    matrix matrixList[500];

    for(int i=0; i<n; i++) {
        cin >> r >> c;
        matrixList[i] = {r, c};
    }

    int dp[500][500] = {0,};

    for(int len=1; len<n; len++) {
        for(int i=0; i+len<n; i++) {
            dp[i][i+len] = INT32_MAX;
            for(int mid=i; mid<i+len; mid++) {
                dp[i][i+len] = min(dp[i][i+len], dp[i][mid]+dp[mid+1][i+len]+matrixList[i].first*matrixList[mid].second*matrixList[i+len].second);
            } 
        }
    }

    cout << dp[0][n-1];
}