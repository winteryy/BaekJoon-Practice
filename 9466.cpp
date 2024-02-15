#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> n;
        vector<int> std(n+1);
        for(int j=1; j<=n; j++) {
            cin >> std[j];
        }

        // vector<bool> flags(n+1, false);
        set<int> flags;
        int cnt = 0;

        for(int j=1; j<=n; j++) {
            // if(flags[j]) continue;
            if(flags.find(j)!=flags.end()) continue;

            set<int> isVisited;
            stack<int> st;
            st.push(j);

            while(true) {
                int cur = st.top();

                // if(flags[cur] || cur<j) break;
                if(flags.find(cur)!=flags.end() || cur<j) break;

                if(isVisited.find(cur)!=isVisited.end()) {
                    st.pop();
                    int num = -1;
                    while(num!=cur) {
                        num = st.top();
                        st.pop();
                        // flags[num] = true;  
                        flags.insert(num);
                    }
                    break;
                }

                isVisited.insert(cur);
                
                st.push(std[cur]);
            }
        }

        // for(int k=1; k<=n; k++) {
        //     if(!flags[k]) {
        //         cnt++;
        //     }
        // }
        cout << n-flags.size() << "\n";
    }

}

