#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> l, pair<int, int> r) {
    if(l.second==r.second) {
        return l.first<r.first;
    } else {
        return l.second<r.second;
    }
}

int main() {
    int n, start, end;
    cin >> n;
    vector<pair<int, int> > v;

    for(int i=0; i<n; i++) {
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), compare);

    int t=0, num=0;
    
    for(auto e: v) {
        if(e.first>=t) {
            t=e.second;
            num++;
        }
    }

    cout << num;
    
}