#include <iostream>

using namespace std;

int main() {
    string exp;
    cin >> exp;

    bool minusFlag = false;
    int result = 0;
    int curNum = 0;
    
    for(int i=0; i<=exp.length(); i++) {
        if(i==exp.length() || exp[i]=='+' || exp[i]=='-') {
            if(minusFlag) {
                result -= curNum;
            } else {
                result += curNum;
            }
            curNum = 0;
            if(exp[i]=='-') minusFlag = true;
        } else {
            curNum *= 10;
            curNum += exp[i]-'0';
        }
    }

    cout << result;
}