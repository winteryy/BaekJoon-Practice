#include <iostream>
#include <list>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    list<char> s;
    string temp;

    int cmdNum;
    cin >> temp >> cmdNum;
    for(auto ch: temp) {
        s.push_back(ch);
    }

    list<char>::iterator iter = s.end();
    char cmdChar, subChar;

    for(int i=0; i<cmdNum; i++) {
        cin >> cmdChar;
        switch(cmdChar) {
            case 'L':
                if(iter!=s.begin()) {
                    iter--;
                }
                break;

            case 'D':
                if(iter!=s.end()) {
                    iter++;
                }
                break;

            case 'B': 
                if(iter!=s.begin()) {
                    iter = s.erase(--iter); 
                }
                break;

            case 'P': 
                cin >> subChar;
                s.insert(iter, subChar);
                break;

            default: break;
        }
    }

    for(auto ch: s) {
        cout << ch;
    }

}