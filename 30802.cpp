#include <iostream>

using namespace std;

int sizeList[6];

int main() {
    int n, t, p;

    cin >> n;
    for(int i=0; i<6; i++) {
        cin >> sizeList[i];
    }
    cin >> t >> p;

    int tNum = 0;
    for(auto num : sizeList) {
        if(num%t==0) {
            tNum += num/t;
        } else {
            tNum += num/t+1;
        }
    }

    cout << tNum << "\n" << n/p << " " << n%p;
}