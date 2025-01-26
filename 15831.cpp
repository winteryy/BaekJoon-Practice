#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, b, w;
    cin >> n >> b >> w;

    string street;
    cin >> street;

    int l=0, r=0;
    int bNum=0, wNum=0;
    int maxLength=0;
    
    if(street[0]=='B') {
        bNum++;
    }else {
        wNum++;
    }

    while(r<n&&l<n) {   
        if(bNum<=b && wNum>=w) {
            maxLength = max(maxLength, r-l+1);
            r++;
            if(street[r]=='B') {
                bNum++;
            }else {
                wNum++;
            }
        }else{
            if(wNum<w) {
                r++;
                if(street[r]=='B') {
                    bNum++;
                }else {
                    wNum++;
                }
            }
            if(bNum>b) {
                if(street[l]=='B') {
                    bNum--;
                }else {
                    wNum--;
                }
                l++;
            }
        }
    }

    cout << maxLength; 
    
}