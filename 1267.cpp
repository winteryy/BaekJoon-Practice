#include <iostream>

using namespace std;

int main() {
    int totalY=0, totalM=0, n, amount;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> amount;
        totalY += 10 + amount/30*10;
        totalM += 15 + amount/60*15;
    }

    if(totalY == totalM) {
        cout << "Y " << "M " << totalY;
    } else if(totalY > totalM) {
        cout << "M " << totalM;
    } else {
        cout << "Y " << totalY;
    }
}