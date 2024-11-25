#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unordered_map<string, int> um;
        
        for(int i=0; i<n; i++) {
            string name, category;
            cin >> name >> category;
            um[category]++;
        }

        int result = 1;
        for(auto p : um) {
            result *= p.second+1;
        }

        cout << --result << "\n";
    }
}