#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int cnt = 0;

    int curLen = -1;
    bool iFlag = true;
    for(int i=0; i<m; i++) {
        if(s[i]=='I') {
            if(iFlag) {
                curLen++;
                iFlag = false;
                if(curLen>=n) {
                    cnt++;
                }
            } else {
                curLen = 0;
                iFlag = false;
            }
        } else {
            if(iFlag) {
                curLen = -1;
            }
            iFlag = true;
        }
    }

    cout << cnt;
}