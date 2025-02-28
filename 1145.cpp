#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(const int& a, const int& b) {
    int bigN = max(a, b);
    int smallN = min(a, b);

    while(bigN%smallN != 0) {
        int tmp = bigN%smallN;
        bigN = smallN;
        smallN = tmp;
    }
    return smallN;
}

int lcm(const int& a, const int& b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> num(5);
    for(int i=0; i<5; i++) {
        cin >> num[i];
    }

    int ans = 987654321;
    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            int lcmNum = lcm(num[i], num[j]);
            for(int k=j+1; k<5; k++) {
                ans = min(ans, (lcmNum*num[k] / gcd(lcmNum, num[k]) ) );
            }
        }
    }

    cout << ans;
}