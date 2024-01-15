#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;

    for(int i=0; i<n; i++) {
        cin >> v[i]; 
    }

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            s.insert(v[i]+v[j]);
        }
    }

    int maxNum = -1;
    int target = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            target = v[i]-v[j];
            if(s.find(target)!=s.end()) {
                maxNum = max(maxNum, v[i]);
            }
        }
    }

    cout << maxNum;
}