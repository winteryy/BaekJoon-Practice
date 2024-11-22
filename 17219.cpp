#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string url, pwd;
    unordered_map<string, string> um;

    for(int i=0; i<n; i++) {
        cin >> url >> pwd;
        um.insert({url, pwd});
    }

    for(int i=0; i<m; i++) {
        cin >> url;
        cout << um[url] << "\n";
    }
}