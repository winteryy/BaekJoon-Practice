#include <iostream>

using namespace std;

int cup[4] = {0, 1, 2, 3};

int main() {
    int m;
    cin >> m;
    int c1, c2;

    while(m--) {
        cin >> c1 >> c2;
        swap(cup[c1], cup[c2]);
    }    

    for(int i=1; i<=3; i++) {
        if(cup[i]==1) {
            cout << i;
            break;
        }
    }
}