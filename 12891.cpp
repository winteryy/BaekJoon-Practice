#include <iostream>

using namespace std;

int currentNum[4] = {0, 0, 0, 0};

void countNum(char c, bool isInc) {
    switch (c) {
        case 'A': isInc?currentNum[0]++:currentNum[0]--; break;
        case 'C': isInc?currentNum[1]++:currentNum[1]--; break;
        case 'G': isInc?currentNum[2]++:currentNum[2]--; break;                   
        case 'T': isInc?currentNum[3]++:currentNum[3]--; break;
        default: break;
    }    
}

int main() {
    int s, p;
    cin >> s >> p;

    string str;

    cin >> str;

    int requireNum[4];

    cin >> requireNum[0] >> requireNum[1] >> requireNum[2] >> requireNum[3];

    for(int i=0; i<p-1; i++) {
        countNum(str[i], true);
    }

    int l=0, r=p-1;
    int cnt = 0;

    while(r<s) {
        countNum(str[r], true);

        if(currentNum[0]>=requireNum[0] && currentNum[1]>=requireNum[1] &&
         currentNum[2]>=requireNum[2] && currentNum[3]>=requireNum[3]) {
            cnt++;
        }

        countNum(str[l], false);
        l++; r++;
    }

    cout << cnt;

}