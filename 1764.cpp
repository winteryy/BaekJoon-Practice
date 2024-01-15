#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<string> nSet;
    vector<string> ans;
    string name;
    for(int i=0; i<n; i++) {
        cin >> name;
        nSet.insert(name);
    }
    for(int i=0; i<m; i++) {
        cin >> name;
        if(nSet.find(name)!=nSet.end()) {
            ans.push_back(name);
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(auto nm: ans) {
        cout << nm << "\n";

    }
}