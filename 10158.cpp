#include <iostream>
#include <vector>

using namespace std;

int main() {
    int w, h, x, y, t;
    cin >> w >> h >> x >> y >> t;

    int nx = (t+x) % (2*w);
    if(nx > w) {
        nx = w - (nx - w);
    }
    int ny = (t+y) % (2*h);
    if(ny > h) {
        ny = h - (ny - h);
    }

    cout << nx << " " << ny;
} 