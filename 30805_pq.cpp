#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arrB[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, num;

    priority_queue<pair<int, int> > pqA;

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> num;
        pqA.push({num, -i});
    }
    cin >> m;
    for(int i=1; i<=m; i++) {
        cin >> arrB[i];
    }

    vector<pair<int, int> > lcs; // {num, aInd}
    int bStartInd = 1;

    while(!pqA.empty()) {
        int topNum = pqA.top().first;
        int topInd = -pqA.top().second;
        pqA.pop();

        if(!lcs.empty() && lcs[lcs.size()-1].second>topInd) continue;

        for(int i=bStartInd; i<=m; i++) {
            if(topNum == arrB[i]) {
                lcs.push_back({topNum, topInd});
                bStartInd = i+1;
                break;
            }
        }
    }

    cout << lcs.size() << "\n";
    for(auto p: lcs) {
        cout << p.first << " ";
    }

}