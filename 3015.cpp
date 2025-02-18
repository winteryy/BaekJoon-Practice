#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, height;
    stack<pair<int, int> > st;
    cin >> n;

    long long ans = 0;
    for(int i=0; i<n; i++) {
        cin >> height;
        int num = 1;

        while(!st.empty() && st.top().first<height) {
            ans += st.top().second;
            st.pop();
        }

        if(!st.empty()) {
            if(st.top().first == height) {
                num += st.top().second;
                ans += st.top().second;
                st.pop();
                
                if(!st.empty()) {
                    ans++;
                }
            } else {
                ans++;
            }
        }

        st.push({height, num});
    }

    cout << ans;
}