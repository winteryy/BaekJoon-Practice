#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<string> prefixes;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;

        prefixes.push_back(s);
    }

    sort(prefixes.begin(), prefixes.end());

    int cnt = 0;
    for(int i=0; i<n-1; i++) {
        bool isPrefix = true;
        for(int j=0; j<prefixes[i].length(); j++) {
            if(j>=prefixes[i+1].length()) break;
            if(prefixes[i][j]!=prefixes[i+1][j]) {
                isPrefix = false;
                break;
            }
        }

        if(!isPrefix) cnt++;
    }

    cout << ++cnt;
}