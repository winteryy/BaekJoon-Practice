#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    vector<int> containAlpha(26, 0);
    
    int maxLength = 0;
    int l=0, r=0;
    int currentAlpha = 1;
    containAlpha[str[0]-'a']++;

    while(r<str.size() && l<str.size()) {

        if(currentAlpha<=n) {
            maxLength = max(maxLength, r-l+1);
            r++;
            if(containAlpha[str[r]-'a']==0) {
                currentAlpha++;
            }
            containAlpha[str[r]-'a']++;
        } else {
            if(containAlpha[str[l]-'a']==1) {
                currentAlpha--;
            }
            containAlpha[str[l]-'a']--;
            l++;
        }
    }

    cout << maxLength;
}