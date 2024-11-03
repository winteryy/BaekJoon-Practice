#include <iostream>
#define MOD 1'000'000'007

using namespace std;

long long pow(long long base, long long exp) {
    if(exp==0) return 1;
    if(exp==1) return base;

    long long half = pow(base, exp/2) % MOD;
    if(exp%2==0) {
        return (half * half) % MOD;
    } else {
        return (((half * half) % MOD) * base) % MOD;
    }
}

long long getModularInverse(long long n) {
    return pow(n, MOD-2); 
}

int main() {
    int m;
    cin >> m;

    long long n, s;
    long long result = 0;

    for(int i=0; i<m; i++) {
        cin >> n >> s;
        
        result = (result + (s*getModularInverse(n)%MOD)) % MOD;
    }

    cout << result;
    
}