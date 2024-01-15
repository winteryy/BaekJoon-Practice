#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int ch, trouble;
    cin >> ch >> trouble;

    vector<bool> normalButton(10, true);
    for(int i=0; i<trouble; i++) {
        int troubleNum;
        cin >> troubleNum;

        normalButton[troubleNum] = false;
    }


    int upperCh, lowerCh;
    if(ch>=100) {
        upperCh = ch+ch-100;
        lowerCh = 100;
    }else {
        upperCh = 100;
        lowerCh = 0;
    }

    int minClick = abs(ch-100);

    for(int i=lowerCh; i<=upperCh; i++) {
        int cnt=0, currentCh=i;
        bool isValid = true;
        while(true) {
            if(normalButton[currentCh%10]) {
                cnt++;
                currentCh/=10;
                if(currentCh==0) {
                    break;
                }
            }else {
                isValid = false;
                break;
            }
        }

        if(isValid) {
            minClick = min(minClick, cnt+abs(ch-i));
        }
    }

    cout << minClick;
}