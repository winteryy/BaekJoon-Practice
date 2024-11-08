#include <iostream>

using namespace std;

class CustomSet {
public:
    bool setArr[21];

    CustomSet() {
        empty();
    }
    void add(int x) {
        setArr[x] = true;
    }
    void remove(int x) {
        setArr[x] = false;
    }
    void check(int x) {
        cout << setArr[x] << "\n";
    }
    void toggle(int x) {
        setArr[x] = !setArr[x];
    }
    void all() {
        for(int i=1; i<=20; i++) {
            setArr[i] = true;
        }
    }
    void empty() {
        for(int i=1; i<=20; i++) {
            setArr[i] = false;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> m;

    string cmd;
    int x;
    CustomSet s;

    while(m--) {
        cin >> cmd;

        switch(cmd[1]) {
        case 'd':
            cin >> x;
            s.add(x);
            break;
        case 'e':
            cin >> x;
            s.remove(x);
            break;
        case 'h':
            cin >> x;
            s.check(x);
            break;
        case 'o':
            cin >> x;
            s.toggle(x);
            break;
        case 'l':
            s.all();
            break;
        case 'm':
            s.empty();
            break;
        }
    }
}