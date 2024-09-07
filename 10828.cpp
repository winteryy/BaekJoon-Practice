#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    stack<int> st;
    string cmd;
    int n, num;

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> cmd;

        if(cmd == "push") {
            cin >> num;
            st.push(num);
        } else if(cmd == "pop") {
            if(st.empty()) {
                cout << "-1\n";
            } else {
                cout << st.top() << "\n";
                st.pop();
            }
        } else if(cmd == "size") {
            cout << st.size() << "\n";
        } else if(cmd == "empty") {
            cout << st.empty() << "\n";
        } else if(cmd == "top") {
            if(st.empty()) {
                cout << "-1\n";
            } else {
                cout << st.top() << "\n";
            }            
        }
    }
    
}