#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, num, x;
    cin >> n;
    vector<bool> nums(1000001, false);

    for(int i=0; i<n; i++) {
        cin >> num;
        nums[num] = true;
    }
    
    cin >> x;
    
    int range;
    int cnt = 0;

    if(x%2==0) {
        range = x/2-1;
    }else {
        range = x/2;
    }
    for(int i=1; i<=range; i++) {
        if(nums[i] && x-i<=1000000 && nums[x-i]) {
            cnt++;
        }
    }

    cout << cnt;

}