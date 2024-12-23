#include <iostream>
#include <vector>
#define MAX_NUM 1000000

using namespace std;

string s;
string cur;
vector<bool> isVisited;
int threshold;
int minValue = MAX_NUM;

void dfs(int depth) {
    if(depth==s.size()) {
        int curInt = stoi(cur);

        if(threshold<curInt && curInt<minValue) {
            minValue = curInt;
        }
    } else {
        for(int i=0; i<isVisited.size(); i++) {
            if(depth==0 && s[i]=='0') continue;

            if(!isVisited[i]) {
                cur.push_back(s[i]);
                isVisited[i] = true;
                dfs(depth+1);
                isVisited[i] = false;
                cur.pop_back();
            }
        }
    }
}

int main() {
    cin >> s;

    isVisited = vector<bool>(s.size(), false);
    threshold = stoi(s);

    dfs(0);

    if(minValue!=MAX_NUM) {
        cout << minValue;
    } else {
        cout << 0;
    }
}