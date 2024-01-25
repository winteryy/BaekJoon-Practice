#include <iostream>
#include <vector>

using namespace std;

string s;
bool checkFlag=false;
int n;
vector<bool> isUsed;
vector<int> ans;

void solve(int ind) {
    if(checkFlag == true) {
        return;
    }
    if(ind==s.size()) {
        for(auto num: ans) {
            cout << num << " ";
        }
        checkFlag = true;
        return;
    }

    int cur = s[ind]-'0';
    if(cur==0) {
        return;
    }

    if(!isUsed[cur]) {
        isUsed[cur] = true;
        ans.push_back(cur);
        solve(ind+1);
        ans.pop_back();
        isUsed[cur] = false;
    }

    if(ind<s.size()-1) {
        cur = cur*10+s[ind+1]-'0';
        if(cur <= n && !isUsed[cur]) {
            isUsed[cur] = true;
            ans.push_back(cur);
            solve(ind+2);
            ans.pop_back();
            isUsed[cur] = false;
        }
    }
}

int main() {

    cin >> s;
    
    if(s.size()>9) {
        n = (s.size()-9)/2 + 9;
    }else {
        n = s.size();
    }

    isUsed = vector<bool> (n, false);

    solve(0);
    
}