#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<int> numList;
int result[8];

void dfs(int prev, int depth) {
    if(depth==m) {
        for(int i=0; i<m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    } else {
        for(int i=prev; i<numList.size(); i++) {
            result[depth] = numList[i];
            dfs(i, depth+1);
        }
    }
}

int main() {
    cin >> n >> m;

    set<int> numSet;
    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        numSet.insert(num);
    }

    for(int num: numSet) {
        numList.push_back(num);
    }

    dfs(0, 0);
}