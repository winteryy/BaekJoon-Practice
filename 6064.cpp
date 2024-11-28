#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if(a%b==0) return b;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int year = -1;
        int endYear = lcm(m, n);
        if(n==y) y = 0;
        
        for(int i=x; i<=endYear; i+=m) {
            int remainY = i%n;
            if(remainY==y) {
                year = i;
                break;
            }
        }
        cout << year << "\n";
    }
}