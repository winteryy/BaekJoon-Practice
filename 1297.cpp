#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int D, H, W;
    cin >> D >> H >> W;

    double d = sqrt(H*H+W*W);

    cout << (int)(D*H/d) << " " << (int)(D*W/d);
}