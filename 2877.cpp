#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    n++;

    stack<bool> s;
    while(n>1) {
        if(n%2==0) {
            s.push(true);
        }else {
            s.push(false);
        }
        n/=2;
    }

    while(!s.empty()) {
        if(s.top()) {
            cout << '4';
        }else {
            cout << '7';
        }
        s.pop();
    }
}