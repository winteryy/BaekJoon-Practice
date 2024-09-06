#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int g, p, num;
    cin >> g >> p;

    set<int> gateSet = set<int>();
    
    for(int i=1; i<=g; i++) {
        gateSet.insert(i);
    }

    int dockedNum = 0;
    bool flag = true;

    for(int i=0; i<p; i++) {
        cin >> num;
        
        if(flag) {
            auto iter = gateSet.upper_bound(num);
            
            if(gateSet.empty()) {
                flag = false;
            } else if(iter != gateSet.begin()) {
                iter--;
                gateSet.erase(iter);
                dockedNum++;
            } else {
                flag = false;
            }
        }
    }

    cout << dockedNum;
}