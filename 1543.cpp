#include <iostream>

using namespace std;

int main() {
    string doc, str;
    getline(cin, doc);
    getline(cin, str);
    
    if(doc.size()<str.size()) {
        cout << "0";
        return 0;
    }
    int cnt = 0;
    for(int i=0; i<=doc.size()-str.size(); i++) {
        if(doc.substr(i, str.size()) == str) {
            cnt++;
            i+=str.size()-1;
        }
    }

    cout << cnt;
}