#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> order;

bool compare(pair<int, int> l, pair<int, int> r) {
    if(l.second==r.second) {
        return order[l.first] < order[r.first];
    }else {
        return l.second > r.second;
    }
}
int main() {

    int n, c, num, orderNum=0;
    cin >> n >> c;

    map<int, int> frequency;

    for(int i=0; i<n; i++) {
        cin >> num;
        if(frequency.find(num)!=frequency.end()) {
            frequency[num]++;
        }else {
            frequency[num] = 1;
            order[num] = orderNum;
            orderNum++;
        }
    }

    vector<pair<int, int> > sortedV;
    for(auto k : frequency) {
        sortedV.push_back(k);
    }

    sort(sortedV.begin(), sortedV.end(), compare);

    for(auto e: sortedV) {
        for(int i=0; i<e.second; i++) {
            cout << e.first << " ";
        }
    }

}