#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> numToName(n+1);
    unordered_map<string, int> nameToNum;

    string name;

    for(int i=1; i<=n; i++) {
        cin >> name;
        numToName[i] = name;
        nameToNum[name] = i; 
    }

    string cmd;

    for(int i=0; i<m; i++) {
        cin >> cmd;
        if(cmd[0]>='A' && cmd[0]<='Z') {
            cout << nameToNum[cmd] << "\n";
        } else {
            cout << numToName[stoi(cmd)] << "\n";
        }
    } 
}