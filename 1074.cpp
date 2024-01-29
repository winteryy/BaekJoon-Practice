#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, r, c;

    cin >> n >> r >> c;

    int exp = pow(2, n);
    int row = 0, col = 0;
    long long order = 0;

    while(exp>1) {
        exp /= 2;
        if(row+exp > r) {
            if(col+exp <= c) {
                col += exp;
                order += exp*exp;
            }
        }else {
            if(col+exp > c) {
                row += exp;
                order += 2*exp*exp;
            }else {
                row += exp;
                col += exp;
                order += 3*exp*exp;
            }
        }
    }

    cout << order;
}