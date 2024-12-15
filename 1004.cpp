#include <iostream>

using namespace std;

bool isInRange(int cx, int cy, int r, int x, int y) {
    int diffX = abs(cx-x);
    int diffY = abs(cy-y);
    if(diffX*diffX + diffY*diffY <= r*r) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    int x1, y1, x2, y2, n;
    int cx, cy, r;

    cin >> t;

    while(t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> n;

        int cnt = 0;
        while(n--) {
            cin >> cx >> cy >> r;

            bool flag1 = isInRange(cx, cy, r, x1, y1);
            bool flag2 = isInRange(cx, cy, r, x2, y2);

            if(flag1 != flag2) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}