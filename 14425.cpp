#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, bool> strMap;
    int n, m;
    cin >> n >> m;

    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        strMap[s] = true;
    }

    int cnt = 0;
    for(int i=0; i<m; i++) {
        cin >> s;
        if(strMap.find(s)!=strMap.end()) {
            cnt++;
        }
    }

    cout << cnt;
}