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

    //pre-processing
    vector<int> pi(m.size(), 0);
    int piInd = 0;
    for(int i=1; i<m.size(); i++) {
        while(piInd>0 && m[i]!=m[piInd]) {
            piInd = pi[piInd-1];
        }
        if(m[i]==m[piInd]) {
            pi[i] = ++piInd;
        }
    }

    //search
    vector<int> matchedInd;

    piInd = 0;
    for(int i=0; i<n.size(); i++) {
        while(piInd>0 && n[i]!=m[piInd]) {
            piInd = pi[piInd-1];
        }
        if(n[i]==m[piInd]) {
            if(piInd == m.size()-1) {
                matchedInd.push_back(i-piInd+1);
                piInd = pi[piInd];
            } else {
                piInd++;
            }
        }
    }

    cout << matchedInd.size() << "\n";
    for(int& ind: matchedInd) {
        cout << ind << " ";
    }
}
