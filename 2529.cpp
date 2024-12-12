#include <iostream>
#include <vector>

using namespace std;

string maxNum, minNum;
vector<char> input;
vector<bool> usedFlag(10, false);
string curNum;
void dfs(int cur, int depth) {
    if(cur==depth) {
        if(maxNum.empty()||maxNum<curNum) {
            maxNum = curNum;
        }
        if(minNum.empty()||minNum>curNum) {
            minNum = curNum;
        }
    } else {
        for(int i=0; i<10; i++) {
            if(!usedFlag[i]) {
                if(cur!=0) {
                    if(input[cur-1]=='<' && curNum[cur-1]>i+'0') continue;
                    if(input[cur-1]=='>' && curNum[cur-1]<i+'0') continue;                     
                }
                curNum.push_back(i+'0');
                usedFlag[i] = true;
                dfs(cur+1, depth);
                curNum.pop_back();
                usedFlag[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    input = vector<char>(n);

    int lessThanNum = 0;
    for(int i=0; i<n; i++) {
        cin >> input[i];
    }

    dfs(0, n+1);

    cout << maxNum << "\n" << minNum;
}    