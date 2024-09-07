#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    queue<int> q;
    string cmd;
    int n, num;

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> cmd;

        if(cmd == "push") {
            cin >> num;
            q.push(num);
        } else if(cmd == "pop") {
            if(q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if(cmd == "size") {
            cout << q.size() << "\n";
        } else if(cmd == "empty") {
            cout << q.empty() << "\n";
        } else if(cmd == "front") {
            if(q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
            }            
        } else if(cmd == "back") {
            if(q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << "\n";
            }            
        }
    }
    
}