#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define a first 
#define b second  

using namespace std;

typedef pair<int, int> connection;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, aNum, bNum;
    vector<connection> connectionList;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> aNum >> bNum;
        connectionList.push_back({aNum, bNum});
    }

    sort(connectionList.begin(), connectionList.end());

    vector<int> dp;
    vector<int> lisInd;
    vector<int> prev(n, -1);

    dp.push_back(connectionList[0].b);
    lisInd.push_back(0);

    for(int i=1; i<n; i++) {
        if(dp[dp.size()-1] < connectionList[i].b) {
            prev[i] = lisInd[dp.size()-1];
            dp.push_back(connectionList[i].b);
            lisInd.push_back(i);
        } else {
            auto lb = lower_bound(dp.begin(), dp.end(), connectionList[i].b);
            *lb = connectionList[i].b;
            lisInd[lb-dp.begin()] = i;
            if(lb-dp.begin()>0) {
                prev[i] = lisInd[lb-dp.begin()-1];               
            }
        }
    }

    unordered_set<int> lis;
    for(int i=lisInd[lisInd.size()-1]; i!=-1; i=prev[i]) {
        lis.insert(connectionList[i].a);
    }

    cout << connectionList.size()-lis.size() << "\n";
    for(auto con: connectionList) {
        if(lis.find(con.a)==lis.end()) {
            cout << con.a << "\n";
        }
    }

}