#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    string s;

    for(int i=0; i<t; i++) {
        cin >> s;
        
        stack<char> left;
        stack<char> right;
        for(auto c: s) {
            if(c=='<') {
                if(!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
            }else if(c=='>') {
                if(!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
            }else if(c=='-') {
                if(!left.empty()) {
                    left.pop();
                }
            }else {
                left.push(c);
            }
        }

        while(!left.empty()) {
            right.push(left.top());
            left.pop();
        }
        while(!right.empty()) {
            cout << right.top();
            right.pop();
        }
        cout << "\n";
    }
}   