#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getCharToNum(char& c) {
    if(isupper(c)) {
        return c - 'A';
    } else if(c==' ') {
        return 52;
    } else {
        return 26 + c - 'a';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string n = "", m = "";
    getline(cin, n);
    getline(cin, m);

    vector<int> skip(53, 1); // 0~25: upper, 26~51: lower, 52: whitespace

    //pre-processing(Bad Character)
    int tableInd;
    for(int i=0; i<m.length(); i++) {
        skip[getCharToNum(m[i])] = m.length()-i-1;
    }

    //search
    vector<int> matchedInd;
    
    int mLast = m.length()-1;
    int cursor = mLast;
    while(cursor<n.length()) {
        bool flag = true;
        int curInd;
        for(int i=0; i<m.length(); i++) {
            curInd = cursor-i;
            if(n[curInd] != m[mLast-i]) {
                flag = false;
                cursor += max(1, skip[getCharToNum(n[curInd])]);
                break;
            }
        }
        if(flag) {
            matchedInd.push_back(cursor-m.length()+2);
            cursor++;
        }
    }

    cout << matchedInd.size() << "\n";
    for(int& ind: matchedInd) {
        cout << ind << " ";
    }
}
