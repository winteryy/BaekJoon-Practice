#include <iostream>
#include <cmath>

using namespace std;

typedef pair<long long, long long> point;


double getDistance(point p1, point p2) {
    return sqrt(pow(abs(p1.first - p2.first), 2) + pow(abs(p1.second - p2.second), 2));
}

double getTriangleArea(point p1, point p2, point p3) {
    double d1 = getDistance(p1, p2);
    double d2 = getDistance(p2, p3);
    double d3 = getDistance(p3, p1);

    double s = (d1+d2+d3)/2;
    
    return sqrt(s*(s-d1)*(s-d2)*(s-d3));
}

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