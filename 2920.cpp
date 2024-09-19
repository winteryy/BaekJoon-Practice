#include <iostream>

using namespace std;

int main() {
    int n;
    bool ascFlag = true;
    bool desFlag = true;
    for(int i=1; i<=8; i++) {
        cin >> n;
        if(ascFlag && i!=n) ascFlag = false;
        if(desFlag && 9-i!=n) desFlag = false;
    }

    if(ascFlag) {
        cout << "ascending";
    } else if(desFlag) {
        cout << "descending";
    } else {
        cout << "mixed";
    }
}