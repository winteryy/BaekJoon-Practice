#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int getMoveCost(int start, int end) {
    if(start==0) {
        return 2;
    } else if(start==end) {
        return 1;
    } else if(start%2==end%2) {
        return 4;
    } else {
        return 3;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    vector<int> ddrNumList;

    cin >> n;

    while(n!=0) {
        ddrNumList.push_back(n);
        cin >> n;
    }

    if(ddrNumList.empty()) {
        cout << "0";
        return 0;
    }

    vector<vector<int> > dp(32, vector<int>(ddrNumList.size(), INF));
    dp[1<<ddrNumList[0] | 1][0] = 2;

    for(int i=1; i<ddrNumList.size(); i++) {
        for(int j=0; j<32; j++) {
            if(dp[j][i-1]!=INF) {
                for(int k=0; k<5; k++) {
                    if(1<<k & j) {
                        int nextPosition = j ^ 1<<k | 1<<ddrNumList[i];
                        if(nextPosition != 1<<ddrNumList[i]) {
                            dp[nextPosition][i] = min(dp[nextPosition][i], dp[j][i-1] + getMoveCost(k, ddrNumList[i]));
                        }
                    }
                }
            }
        }
    }

    int minCost = INF;
    for(int i=0; i<32; i++) {
        minCost = min(minCost, dp[i][ddrNumList.size()-1]);
    }

    cout << minCost;
}