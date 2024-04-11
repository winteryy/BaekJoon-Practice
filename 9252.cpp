#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int> > dp(s1.size()+1, vector<int>(s2.size()+1, 0));

    for(int i=1; i<=s1.size(); i++) {
        for(int j=1; j<=s2.size(); j++) {
            dp[i][j] = (s1[i-1]==s2[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]));
        }
    }

    int i = s1.size();
    int j = s2.size();
    vector<char> revLcs;
    while(i>0 && j>0) {
        if(s1[i-1]==s2[j-1]) {
            revLcs.push_back(s1[i-1]);
            i--;
            j--;
        }else {
            if(dp[i-1][j]>dp[i][j-1]) {
                i--;
            }else {
                j--;
            }
        }
    }
    
    cout << dp[s1.size()][s2.size()] << "\n";
    for(int k=revLcs.size()-1; k>=0; k--) {
        cout << revLcs[k];
    }
}