#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[1<<15][100] = {0, };

int getRemainder(const string& num, int divisor) {
    int prevNum = 0;
    for(auto c: num) {
        prevNum = (prevNum*10+(c-'0')) % divisor;
    }
    return prevNum;
}

long long gcd(long long l, long long r) {
    long long big, small;

    big = max(l, r);
    small = min(l, r);

    while(small != 0) {
        long long remain = big % small;
        big = small;
        small = remain;
    }

    return big;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;
    vector<string> numSet(n);
    vector<int> remainderArr(n);
    vector<int> decimalRemainderArr(51);
    for(int i=0; i<n; i++) {
        cin >> numSet[i];
    }
    cin >> k;

    for(int i=0; i<n; i++) {
        remainderArr[i] = getRemainder(numSet[i], k);
    }

    decimalRemainderArr[0] = 1%k;
    for(int i=1; i<51; i++) {
        decimalRemainderArr[i] = (decimalRemainderArr[i-1]*10) % k;
    }

    int bitRange = 1 << n;
    dp[0][0] = 1;
    for(int i=0; i<bitRange; i++) {
        for(int j=0; j<n; j++) {
            if((i&(1<<j)) == 0) {
                for(int l=0; l<k; l++) { // cur == dp[i][l]
                    int target = ((l*decimalRemainderArr[numSet[j].length()])%k + remainderArr[j]) % k;
                    dp[i|1<<j][target] += dp[i][l];
                }
            } 
        }
    }

    long long p, q=1;

    p = dp[(1<<n)-1][0];
    for(int i=1; i<=n; i++) {
        q *= (long long)i;
    }
    
    long long gcdResult = gcd(p, q);

    cout << p/gcdResult << "/" << q/gcdResult;
}