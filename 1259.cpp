#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    bool flag = true;

    for(int i=0; i<s.size()+1/2; i++) {
        if(s[i]!=s[s.size()-1-i]) {
            flag = false;
            break;
        }
    }

    return flag;
}

int main() {
    string s;
    cin >> s;

    while(s!="0") {
        cout << (isPalindrome(s) ? "yes" : "no") << "\n";
        cin >> s;
    }
}