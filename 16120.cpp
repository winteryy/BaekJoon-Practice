#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    stack<char> s;
    char c;
    while(true) {
        cin >> c;
        if(cin.eof()) {
            break;
        }
        if(s.size()>2) {
            vector<char> temp;
            
            temp.push_back(s.top());
            s.pop();
            temp.push_back(s.top());
            s.pop();
            temp.push_back(s.top());
            s.pop();

            if(temp[2]=='P' && temp[1]=='P' && temp[0]=='A' && c=='P') {
                s.push('P');
            }else {
                for(int i=2; i>=0; i--) {
                    s.push(temp[i]);
                }
                s.push(c);
            }
        }else {
            s.push(c);
        }
    }


    if(s.size()==1 && s.top()=='P') {
        cout << "PPAP";
    }else {
        cout << "NP";
    }
}