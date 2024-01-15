#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;
    for(int i=0; i<s.size(); i++) {
        if(i<s.size()-1) {
            if(s[i]=='(' && s[i+1]==')') {
                st.push(2);
                i++;
            }else if(s[i]=='[' && s[i+1]==']') {
                st.push(3);
                i++;
            }else {
                switch (s[i]) 
                {
                case '(': st.push(-1); break;
                case ')': st.push(-2); break;                
                case '[': st.push(-3); break;
                case ']': st.push(-4); break;                
                default:
                    break;
                }
            }
        }else{
            switch (s[i]) 
            {
            case '(': st.push(-1); break;
            case ')': st.push(-2); break;                
            case '[': st.push(-3); break;
            case ']': st.push(-4); break;                
            default:
                st.push(s[i]-'0');
            }
        }
    }

    stack<int> closeSt;
    int current = 0;
    int total = 0;  
    bool valid = true;  
    while(!st.empty()) {
        if(st.top()==2) {
            current += 2;
        }else if(st.top()==3) {
            current += 3;
        }else if(st.top()==-2 || st.top()==-4) {
            if(current != 0) {
                closeSt.push(current);
                current = 0;
            }
            closeSt.push(st.top());
        }else if(st.top()==-1) {
            if(closeSt.empty()){
                valid = false;
                break;
            }
            while(!closeSt.empty() && closeSt.top()>=0) {
                current+=closeSt.top();
                closeSt.pop();
            }
            if(!closeSt.empty()&&closeSt.top()==-2) {
                current*=2;
                closeSt.pop();
            }else {
                valid = false;
                break;
            }
        }else if(st.top()==-3) {
            if(closeSt.empty()){
                valid = false;
                break;
            }
            while(!closeSt.empty() && closeSt.top()>=0) {
                current+=closeSt.top();
                closeSt.pop();
            }
            if(!closeSt.empty()&&closeSt.top()==-4) {
                current*=3;
                closeSt.pop();
            }else {
                valid = false;
                break;
            }
        }
        if(closeSt.empty()) {
            total+=current;
            current=0;
        }
        st.pop();
    }

    if(valid&&closeSt.empty()) {
        cout << total;
    }else {
        cout << 0;
    }
}