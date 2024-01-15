#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    string cmd;
    for(int i=0; i<t; i++) {
        cin >> cmd;
        int n;
        cin >> n;
        deque<int> dq(n);
        char c;
        cin >> c;
        for(int j=0; j<n; j++) {
            cin >> dq[j];
            cin >> c;
        }
        if(n==0) {
            cin >> c;
        }
        bool isReversed = false;
        bool isError = false;
        for(int j=0; j<cmd.size(); j++) {
            if(cmd[j]=='R') {
                isReversed = !isReversed;
            }else if(cmd[j]=='D') {
                if(dq.empty()) {
                    isError = true;
                    break;
                }else {
                    if(isReversed) {
                        dq.pop_back();
                    }else {
                        dq.pop_front();
                    }

                }
            }
        }

        if(isError) {
            cout << "error\n";
        }else if(isReversed) {
            cout << '[';
            if(dq.empty()) {
                cout << "]\n";
            }
            while(!dq.empty()) {
                if(dq.size()==1) {
                    cout << dq.back() << "]\n";
                    break;
                }
                cout << dq.back() << ',';
                dq.pop_back();
            }
        }else {
            cout << '[';
            if(dq.empty()) {
                cout << "]\n";
            }
            while(!dq.empty()) {
                if(dq.size()==1) {
                    cout << dq.front() << "]\n";
                    break;
                }
                cout << dq.front() << ',';
                dq.pop_front();
            }
        }
    }

}