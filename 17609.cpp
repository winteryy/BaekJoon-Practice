#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strArr(n);
    for(int i=0; i<n; i++) {
        cin >> strArr[i];
    }

    vector<int> ans;

    for(auto str: strArr) {
        int l=0, r=str.size()-1;
        int l2=-1, r2=-1;
        bool oneFault = false;
        int palNum = 0;
        while(l<=r) {
            if(str[l]==str[r]) {
                l++;
                r--;
            }else if(!oneFault) {
                if(str[l+1]==str[r]) {
                    if(str[l]==str[r-1]) {
                        l2=l;
                        r2=r-1;
                    }
                    oneFault = true;
                    palNum = 1;
                    l++;
                }else if(str[l]==str[r-1]) {
                    oneFault = true;
                    palNum = 1;
                    r--;
                }else {
                    palNum = 2;
                    break;
                }
            }else {
                palNum = 2;
                break;
            }
        }

        if(l2!=-1&&palNum==2) {
            palNum=1;
            while(l2<=r2) {
                if(str[l2]==str[r2]) {
                    l2++;
                    r2--;
                }else {
                    palNum=2;
                    break;
                }            
            }
        }

        cout << palNum << "\n";
    }
}