#include <iostream>
#include <stack>

using namespace std;

int getPriority(char op) {

    switch(op) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return -1;
    }

}

bool isWord(char op) {

    return 'A'<=op&&'Z'>=op;

}

int main() {
    string originFix;
    cin >> originFix;

    stack<char> opStack;
    string modifiedFix;

    for(int i=0; i<originFix.size(); i++) {
        if(isWord(originFix[i])) {
            modifiedFix.push_back(originFix[i]);
        }else {
            if(originFix[i]=='('){
                opStack.push('(');
            }else if(originFix[i]==')') {
                while(opStack.top()!='(') {
                    modifiedFix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.pop();
            }else if(opStack.empty()||getPriority(opStack.top())<getPriority(originFix[i])) {
                opStack.push(originFix[i]);
            }else{
                while(!(opStack.empty()||getPriority(opStack.top())<getPriority(originFix[i]))) {
                    modifiedFix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(originFix[i]);
            }
        }
    }

    while(!opStack.empty()) {
        modifiedFix.push_back(opStack.top());
        opStack.pop();
    }

    cout << modifiedFix;

}