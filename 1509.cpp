#include <iostream>
#include <algorithm>

using namespace std;

int palindromeMatrix[2500][2500] = {0, };
string s;

int isPalindrome(int start, int end) {
    if(palindromeMatrix[start][end]!=0) {
        return palindromeMatrix[start][end];
    }

    if(s[start]==s[end]) {
        if(end-start<2) return 1;

        if(palindromeMatrix[start+1][end-1]==0) {
            palindromeMatrix[start+1][end-1] = isPalindrome(start+1, end-1);
        }
        return palindromeMatrix[start+1][end-1];
    } else {
        return -1;
    }
}

int main() {
    cin >> s;
    int len = s.length();

    for(int i=0; i<len; i++) {
        for(int j=i; j<len; j++) {
            palindromeMatrix[i][j] = isPalindrome(i, j);
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