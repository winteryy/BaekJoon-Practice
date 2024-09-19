#include <iostream>
#define MOD 1234567891

using namespace std;

int main() {
    int n;
    cin >> n;
    char c;

    long long result = 0;
    long long multi = 1;

    for(int i=0; i<n; i++) {
        cin >> c;
        result += multi * (c-'a'+1) % MOD;
        multi = multi * 31 % MOD; 
    }

    cout << result % MOD;
}