#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, num;
    cin >> n;
    string s;
    deque<int> dq;
    for(int i=0; i<n; i++) {
        cin >> s;

        if(s=="push_back") {
            cin >> num;
            dq.push_back(num);
        }else if(s=="push_front") {
            cin >> num;
            dq.push_front(num);
        }else if(s=="front") {
            if(dq.empty()) {
                cout << "-1\n";
            }else {
                cout << dq.front() << "\n";
            }
        }else if(s=="back") {
            if(dq.empty()) {
                cout << "-1\n";
            }else {
                cout << dq.back() << "\n";
            }
        }else if(s=="empty") {
            cout << dq.empty() << "\n";
        }else if(s=="size") {
            cout << dq.size() << "\n";
        }else if(s=="pop_front") {
            if(dq.empty()) {
                cout << "-1\n";
            }else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }else if(s=="pop_back") {
            if(dq.empty()) {
                cout << "-1\n";
            }else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
    }
}