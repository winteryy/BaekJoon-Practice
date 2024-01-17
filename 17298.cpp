#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, num;
    cin >> n;

    vector<int> ans(n, -1);
    stack<pair<int, int> > st; //first: ind, second: value
    
    for(int i=0; i<n; i++) {
        cin >> num;

        if(st.empty()) {
            st.push(make_pair(i, num));
        }else {
            while(!st.empty() && st.top().second<num) {
                ans[st.top().first] = num;
                st.pop();
            }
            st.push(make_pair(i, num));
        }
    }

    for(auto nge: ans) {
        cout << nge << " ";
    }
}