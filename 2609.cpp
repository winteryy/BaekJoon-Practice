#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int big = a;
    int small = b;

    if(a<b) {
        big = b;
        small = a;
    }

    int r;

    while(small!=0) {
        r = big % small;
        big = small;
        small = r;
    }

    return big;
}

int lcm(int a, int b) {
    
}

int main() {
    int n, m, gcdNum;

    cin >> n >> m;
    gcdNum = gcd(n, m);

    cout << gcdNum << "\n" << n*m/gcdNum;
}