#include<iostream>
#include<vector>
#include<stack>
#include<iomanip>

using namespace std;

bool isWord(char op) {

    return 'A'<=op&&'Z'>=op;

}

double calc(double lNum, double rNum, char op) {
    switch(op) {
        case '+': return lNum+rNum;
        case '-': return lNum-rNum;
        case '*': return lNum*rNum;
        case '/': return lNum/rNum;                        
    }
}

int main() {
    
    int n;
    string expression;
    cin >> n >> expression;

    vector<int> wToN;
    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        wToN.push_back(num);
    }

    stack<double> numStack;
    for(int i=0; i<expression.size(); i++) {
        if(isWord(expression[i])) { 
            numStack.push(wToN[expression[i]-'A']);
        } else {
            double rNum = numStack.top();
            numStack.pop();
            double lNum = numStack.top();
            numStack.pop();
            numStack.push(calc(lNum, rNum, expression[i]));
        }
    }
    cout << fixed;
    cout << setprecision(2) << numStack.top();
}