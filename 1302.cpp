#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {

    map<string, int> m;
    int n, maxNum;
    cin >> n;
    
    string s;
    maxNum = 0;
    for(int i=0; i<n; i++) {
        cin >> s;
        
        if(m.find(s) != m.end()) {
            m[s]++;
        }else{
            m.insert(make_pair(s, 1));
        }

        maxNum = max(maxNum, m[s]);
    }

    vector<string> answers;

    for(auto iter=m.begin(); iter!=m.end(); iter++) {
        if(iter->second == maxNum) {
            answers.push_back(iter->first);
        }
    }

    sort(answers.begin(), answers.end());
    cout << answers[0];
}

