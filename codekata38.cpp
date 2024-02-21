#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    
    string s = "";
    for(int i=0; i<n; i++) {
        s += '*';
    }
    for(int i=0; i<m; i++) {
        cout << s << '\n';
    }
    return 0;
}