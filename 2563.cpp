#include <iostream>

using namespace std;

bool board[100][100] = {false, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int hg, vg;
        cin >> hg >> vg;

        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                board[vg+i][hg+j] = true;
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(board[i][j] == true) cnt++;
        }
    }

    cout << cnt;
}