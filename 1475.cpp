#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(10, 0);
    while(n>0) {
        nums[n%10]++;
        n/=10;
    }

    int need = 0;
    int sixAndNine = 0;
    for(int i=0; i<10; i++) {
        if(i==6 || i==9) {
            sixAndNine += nums[i];
        }else {
            need = max(need, nums[i]);
        }
    }

    need = max(need, (sixAndNine+1)/2);
    cout << need;

}