#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if(n==0) {
        cout << 0;
        return 0;
    }
    vector<int> v(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int minusNum = round(n*0.15);

    for(int i=minusNum; i<n-minusNum; i++) {
        sum += v[i];
    }

    cout << (int)round((double)sum/(n-minusNum*2));
    
}