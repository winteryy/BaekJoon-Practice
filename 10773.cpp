#include <iostream>
#include <stack>

using namespace std;

int main() {
    int k;
    cin >> k;

    int num;
    stack<int> st;
    for(int i=0; i<k; i++) {
        cin >> num;
        if(num==0) {
            st.pop();
        } else {
            st.push(num);
        }
    }

    long long sum = 0;

    while(!st.empty()) {
        sum+=st.top();
        st.pop();
    }

    cout << sum;
}