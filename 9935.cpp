#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main(){
    string s, p;
    cin >> s >> p;

    stack<char> strStack;
    for(int i=0; i<s.size(); i++){
        strStack.push(s[i]);
        if(strStack.size()>=p.size() && strStack.top()==p[p.size()-1]){
            stack<char> tempS;
            for(int j=p.size()-1; j>=0; j--){
                if(strStack.top()==p[j]){
                    tempS.push(strStack.top());
                    strStack.pop();
                }
            }
            if(tempS.size()<p.size()){
                while(!tempS.empty()){
                    strStack.push(tempS.top());
                    tempS.pop();
                }
            }
        }
    }
    stack<char> newS;
    if(strStack.empty()){
        cout << "FRULA";
        return 0;
    }
    while(!strStack.empty()){
        newS.push(strStack.top());
        strStack.pop();
    }
    while(!newS.empty()){
        cout << newS.top();
        newS.pop();
    }
}