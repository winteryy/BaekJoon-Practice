#include <iostream>
#define MOD 1000000007

using namespace std;

long long power(int n, int exp) {
    if(exp == 0) return 1;

    long long half = power(n, exp/2) % MOD;
    if(exp%2==0) {
        return half * half % MOD;
    } else {
        return half * half % MOD * n % MOD;
    }
}

int binomialCoefficient(int n, int k) {
    if(k==0 || k==n) return 1;
    if(k==1) return n;

    long long a = 1, b = 1;
    
    for(int i=n; i>=n-k+1; i--) {
        a = (a*i)%MOD;
    }
    for(int i=1; i<=k; i++) {
        b = b*i%MOD;
    } 
    
    return a * power(b, MOD-2) % MOD;
}

int main() {
    int n, k;

    cin >> n >> k;

    cout << binomialCoefficient(n, k);
}