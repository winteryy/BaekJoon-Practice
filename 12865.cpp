#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Obj{
    int w, v;
};

int main(){
    int n, k;
    cin >> n >> k;

    vector<Obj> objs(n+1);

    for(int i=1; i<=n; i++){
        cin >> objs[i].w >> objs[i].v;
    }

    vector<vector<int> > dp(n+1, vector<int>(k+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(objs[i].w>j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-objs[i].w]+objs[i].v);
            }
        }
    }

    cout << dp[n][k];

}