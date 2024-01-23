#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l, c, cons=0, vow=0;
vector<char> cArr;
vector<char> ans;

bool isVowel(char ch) {
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

void comb(int prev, int current) {
    if(current > l) {
        if(cons<2 || vow<1) {
            return;
        }
        for(auto ch: ans) {
            cout << ch;
        }
        cout << "\n";
        return;
    }else {
        for(int i=prev+1; i<c; i++) {
            ans.push_back(cArr[i]);
            if(isVowel(cArr[i])) {
                vow++;
            }else {
                cons++;
            }

            comb(i, current+1);

            if(isVowel(cArr[i])) {
                vow--;
            }else {
                cons--;
            }
            ans.pop_back();
        }
    }
}

int main() {

    cin >> l >> c;

     cArr = vector<char>(c);
    
    for(int i=0; i<c; i++) {
        cin >> cArr[i];
    }

    sort(cArr.begin(), cArr.end());

    comb(-1, 1);
}