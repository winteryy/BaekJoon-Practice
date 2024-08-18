#include <iostream>
#include <algorithm>

using namespace std;

bool palindromeMatrix[2500][2500] = {false, };
string s;

bool isPalindrome(int start, int end) {
    if(s[start]==s[end]) {
        if(end-start<2) return true;

        return palindromeMatrix[start+1][end-1];
    } else {
        return false;
    }
}

int main() {
    cin >> s;
    int len = s.length();

    for(int i=0; i<len; i++) {
        for(int j=0; j+i<len; j++) {
            palindromeMatrix[j][j+i] = isPalindrome(j, j+i);
        }
    }

    int dp[2501] = {0, };

    for(int i=0; i<len; i++) {
        dp[i+1] = dp[i]+1;
        for(int j=0; j<i; j++) {
            if(palindromeMatrix[j][i]==1) {
                dp[i+1] = min(dp[i+1], dp[j]+1);
            }
        }
    }

    cout << dp[len];
    
}