#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);

    while(s!=".") {
        stack<char> st;
        stack<char> closeSt;
        for(auto c : s) {
            if(c=='[' || c==']' || c=='(' || c==')') {
                st.push(c);
            }
        }

        bool valid = true;
        while(!st.empty()) {
            if(st.top()==']' || st.top()==')') {
                closeSt.push(st.top());
                st.pop();
            }else {
                if(closeSt.empty()){
                    valid = false;
                    break;
                }else {
                    if((st.top()=='[' && closeSt.top()==']') || (st.top()=='(' && closeSt.top()==')')) {
                        st.pop();
                        closeSt.pop();
                    }else {
                        valid = false;
                        break;
                    }
                }
            }
        }

        if(closeSt.empty() && valid) {
            cout << "yes\n";
        }else {
            cout << "no\n";

        }

        getline(cin, s);
    }


}