#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long result = n;
    for(long long i=2; i*i<=n; i++) {
        if(n%i==0) {
            result -= result/i;
            while(n%i==0) n /= i;
        }
    }

    if(n>1) result -= result/n;
    cout << result;
}