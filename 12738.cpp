#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> lis;
    int num;
    while(n--) {
        cin >> num;

        if(lis.empty() || lis.back()<num) {
            lis.push_back(num);
        } else {
            auto iter = lower_bound(lis.begin(), lis.end(), num);
            *iter = num;
        }
    }

    cout << lis.size();
}