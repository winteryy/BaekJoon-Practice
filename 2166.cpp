#include <iostream>
#include <cmath>

using namespace std;

typedef pair<long long, long long> point;

int main() {
    int n;
    cin >> n;

    point pointArr[10001];

    double sum1 = 0;
    double sum2 = 0;

    for(int i=0; i<n; i++) {
        cin >> pointArr[i].first >> pointArr[i].second;
    }
    pointArr[n] = pointArr[0];

    for(int i=0; i<n; i++) {
        sum1 += pointArr[i].first*pointArr[i+1].second;
        sum2 += pointArr[i+1].first*pointArr[i].second;
    }
    
    cout << fixed;
    cout.precision(1);
    cout << abs(sum1-sum2) / 2;
}