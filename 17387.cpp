#include <iostream>

using namespace std;

typedef pair<int, int> point; // {x, y}
typedef pair<double, double> line; // {a, b}, ax + b 

line getLineFunc(point p1, point p2) {
    double a = (double)(p1.second-p2.second) / (p1.first-p2.first);
    double b = p1.second - a*p1.first;

    return {a, b};
}

bool isOnLine(point p1, point p2, double x) {
    if(p1.first<p2.first && p1.first<=x && p2.first>=x) {
        return true;
    } else if(p1.first>=p2.first && p1.first>=x && p2.first<=x) {
        return true;
    } else {
        return false;
    }
}

bool isOverlapped(point a1, point a2, point b1, point b2) {
    int aMinX, aMaxX, bMinX, bMaxX;
    if(a1.first<a2.first) {
        aMinX = a1.first;
        aMaxX = a2.first;
    } else {
        aMinX = a2.first;
        aMaxX = a1.first;
    }

    if(b1.first<b2.first) {
        bMinX = b1.first;
        bMaxX = b2.first;
    } else {
        bMinX = b2.first;
        bMaxX = b1.first;
    }

    return ((aMinX>bMinX && bMaxX>=aMinX) || (aMinX<=bMinX && aMaxX>=bMinX));
}

int main() {
    point a1, a2, b1, b2;

    cin >> a1.first >> a1.second >> a2.first >> a2.second >> b1.first >> b1.second >> b2.first >> b2.second;

    line l1 = getLineFunc(a1, a2);
    line l2 = getLineFunc(b1, b2);
    
    if(l1.first-l2.first==0) {
        if(l1.second-l2.second==0 && isOverlapped(a1, a2, b1, b2)) {
            cout << "1";
        } else {
            cout << "0";
        }
    } else {
        double crossX = -(l1.second-l2.second) / (l1.first-l2.first);
        if(isOnLine(a1, a2, crossX) && isOnLine(b1, b2, crossX)) {
            cout << "1";
        } else {
            cout << "0";
        }
    }

}