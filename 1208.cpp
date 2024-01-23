#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> nums;
map<int, int> m;
long long cnt = 0;
int s;

void combForMap(int prev, int current, int depth, int sum) {
    if(current > depth) {
        m[sum]++;
    }else {
        for(int i=prev+1; i<nums.size()/2; i++) {
            combForMap(i, current+1, depth, sum+nums[i]);
        }
    }
}

void comb(int prev, int current, int depth, int sum) {
    if(current > depth) {
        cnt += m[s-sum];
    }else {
        for(int i=prev+1; i<nums.size(); i++) {
            comb(i, current+1, depth, sum+nums[i]);
        }
    }
}

int main() {
    int n;
    cin >> n >> s;

    nums = vector<int> (n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    for(int i=0; i<=nums.size()/2; i++) {
        combForMap(-1, 1, i, 0);
    }
    for(int i=0; i<=nums.size()-(nums.size()/2); i++) {
        comb(nums.size()/2-1, 1, i, 0);
    }

    if(s==0) {
        cnt--;
    }

    cout << cnt;

}