#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;
struct Point{
    ll x, y;
};
vector<Point> p;
int N;

ll ccw(Point p1, Point p2, Point p3){
    return p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y);
}

bool cmpY(Point p1, Point p2){
    if (p1.y == p2.y) return p1.x < p2.x;
    else return p1.y < p2.y;
}

bool cmpC(Point p1, Point p2){
    ll cp = ccw(p[0], p1, p2);
    if (cp == 0) return (abs(p1.x-p[0].x) + abs(p1.y-p[0].y)) < (abs(p2.x-p[0].x) + abs(p2.y-p[0].y));
    return cp > 0;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    p.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p.begin(), p.end(), cmpY);
    sort(p.begin()+1, p.end(), cmpC);

    vector<Point> v;
    v.push_back(p[0]);
    v.push_back(p[1]);

    for (int i = 2; i < N; i++) {
        while (v.size() >= 2) {
            Point p2 = v.back();
            v.pop_back();
            Point p1 = v.back();
            if (ccw(p1, p2, p[i]) > 0) {
                v.push_back(p2);
                break;
            }
        }
        v.push_back(p[i]);
    }
    cout << v.size() <<  '\n';
}