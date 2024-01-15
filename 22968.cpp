#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int n, v;
    cin >> n;
    
    vector<int> vList;

    for(int i=0; i<n; i++) {
        cin >> v;
        vList.push_back(v);
    }

    vector<int> answer;


    vector<int> dp(44, 0);
    dp[1] = 1;
    dp[2] = 2;

    for(int i=0; i<n; i++) {

        for(int j=1; j<44; j++) {
            if(dp[j]==0) {
                dp[j]=dp[j-1]+dp[j-2]+1;
            }

            if(vList[i]<dp[j]) {
                answer.push_back(j-1);
                break;
            }
        }

    }
    


    // for(int i=0; i<n; i++) {
    //     cout << answer[i] << "\n";
    // }

    for(auto i: answer) {
        cout << i << "\n";
    }
}