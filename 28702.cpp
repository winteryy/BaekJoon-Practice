#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    bool flag = false;

    for(int i=3; i>=1; i--) {
        cin >> s;
        if(!flag && isdigit(s[0])) {
            int n = stoi(s);
            n+=i;
        
            if(n%3==0 && n%5==0) {
                cout << "FizzBuzz";
            } else if(n%3 == 0) {
                cout << "Fizz";
            } else if(n%5 == 0) {
                cout << "Buzz";
            } else {
                cout << n;
            }

            flag = true;
        }
    }
}