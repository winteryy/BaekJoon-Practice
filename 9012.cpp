#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, left;
    string s;

    cin >> n;

    for(int i=0; i<n; i++) {
        left = 0;
        cin >> s;
        for(char c: s) {
            if(c=='(') {
                left++;
            } else if(left>0) {
                left--;
            } else {
                left = 1;
                break;
            }
        }

        if(left>0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}