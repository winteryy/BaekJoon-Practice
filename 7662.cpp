#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k, n;
    char cmd;
    cin >> t;

    while(t--) {
        cin >> k;
        multiset<int> ms;

        while(k--) {
            cin >> cmd >> n;
            if(cmd=='I') {
                ms.insert(n);
            } else if(!ms.empty()) {
                if(n==1) {
                    ms.erase(--ms.end());
                } else {
                    ms.erase(ms.begin());
                }
            } 
        }

        if(ms.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *(--ms.end()) << " " << *ms.begin() << "\n";
        }
    }
}