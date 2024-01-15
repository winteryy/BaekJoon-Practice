#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<char> circle(n, '?');
    vector<bool> used(26, false);
    stack<pair<int, char> > st;

    int move;
    char ch;
    for(int i=0; i<k; i++) {
        cin >> move >> ch;
        st.push(make_pair(move, ch));
    }

    int ind=0;

    while(!st.empty()) {
        if(circle[ind]=='?') {
            if(used[st.top().second-'A']) {
                cout << "!";
                return 0;
            }

            used[st.top().second-'A'] = true;
            circle[ind] = st.top().second;
            ind = (ind+st.top().first) % n;
        }else if(circle[ind]==st.top().second) {
            ind = (ind+st.top().first) % n;
        }else {
            cout << "!";
            return 0;
        }  
        st.pop();  
    }


    for(auto c : circle) {
        cout << c;
    }
}