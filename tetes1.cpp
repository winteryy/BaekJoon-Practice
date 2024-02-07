#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int> > v;
        for(int i=lo; i<=hi; i++) {
            v.push_back({getPower(i), i});
        }
        sort(v.begin(), v.end());

        return v[k-1].second;
    }
    int getPower(int n) {
        int count = 0;
        while(n>1) {
            if(n%2==0) {
                n/=2;
            }else {
                n = n*3+1;
            }
            count++;
        }
        return count;
    }
};


int main() {
    Solution sl;
    cout <<    sl.getKth(7, 11, 4);

}