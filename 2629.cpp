#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int bound = 0;

    vector<int> weight(n+1);
    for(int i=1; i<=n; i++){
        cin >> weight[i];
        bound += weight[i];
    }

    vector<vector<bool> > dp(n+1, vector<bool>(bound+1, false));
    dp[0][0] = true;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=bound; j++){
            if(dp[i-1][j] || (j+weight[i]<=bound && dp[i-1][j+weight[i]]) || (abs(j-weight[i])>=0 && dp[i-1][abs(j-weight[i])])){
                dp[i][j] = true;
            }
        }
    }
    int ballNum;
    cin >> ballNum;
    vector<int> balls(ballNum);
    for(int i=0; i<ballNum; i++){
        cin >> balls[i];
    } 

    for(int i=0; i<ballNum; i++){
        if(balls[i]>bound){
            cout << "N ";
        }else if(dp[n][balls[i]]){
            cout << "Y ";
        }else{
            cout << "N ";
        }
    }


}