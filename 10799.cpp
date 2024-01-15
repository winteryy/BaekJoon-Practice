#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    stack<char> st;
    for(char c: s) {
        st.push(c);
    }
    int total = 0;
    int current = 0;
    while(!st.empty()) {
        char cur = st.top();
        st.pop();

        if(cur==')' && st.top()=='(') {
            total += current;
            st.pop();
        }else if(cur==')') {
            current++;
        }else {
            current--;
            total++;
        }
    }

    cout << total;
}