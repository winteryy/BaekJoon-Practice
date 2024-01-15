#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, num;
    cin >> n;
    map<int, int> cardMap;

    for(int i=0; i<n; i++) {
        cin >> num;
        if(cardMap.find(num)!=cardMap.end()){
            cardMap[num]++;
        }else {
            cardMap[num] = 1;
        }
    }

    cin >> m;
    vector<int> targetArr(m);
    vector<int> answers;
    for(int i=0; i<m; i++) {
        cin >> targetArr[i];
    }

    for(auto t: targetArr) {
        if(cardMap.find(t)!=cardMap.end()) {
            answers.push_back(cardMap[t]);
        } else {
            answers.push_back(0);
        }
    }

    for(auto answer: answers) {
        cout << answer << " ";
    }
}