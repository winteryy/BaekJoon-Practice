#include <iostream>
#include <vector>
#include <string>

using namespace std;

int exist[53]; // 0~25: upper, 26~51: lower, 52: whitespace

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string n = "", m = "";
    getline(cin, n);
    getline(cin, m);

    fill(begin(exist), end(exist), -1);

    vector<int> skip(m.length()+1);

    //pre-processing(Bad Character)
    int tableInd;
    int mLast = m.length()-1;
    for(int i=0; i<m.length(); i++) {
        if(isupper(m[i])) {
            tableInd = m[i] - 'A';
        } else if(m[i]==' ') {
            tableInd = 52;
        } else {
            tableInd = 26 + m[i] - 'a';
        }

        if(exist[tableInd]==-1) {
            skip[i] = max(1, mLast-i);
        } else {
            skip[i] = i-exist[tableInd];
        }
        exist[tableInd] = i;
    }

    skip[m.length()] = 1;

    //search
    vector<int> matchedInd;
    
    int cursor = mLast;
    while(cursor<n.length()) {
        bool flag = true;
        int curInd;
        for(int i=0; i<m.length(); i++) {
            curInd = cursor-i;
            if(n[curInd] != m[mLast-i]) {
                flag = false;
                cursor += skip[mLast-i+1];
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
