#include <iostream>

using namespace std;

int binomialCoefficient(int n, int k) {
    if(k==0) return 1;
    if(k==n) return 1;

    return binomialCoefficient(n-1, k-1) + binomialCoefficient(n-1, k);
}

int main() {
    int n, k;

    cin >> n >> k;

    cout << binomialCoefficient(n, k);
}