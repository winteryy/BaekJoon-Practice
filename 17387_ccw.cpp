#include <iostream>

using namespace std;

typedef pair<int, int> point;
typedef pair<int, int> vector;

vector getVector(point start, point end) {
    return {end.first - start.first, end.second - start.second};
}

int getCCW(vector start, vector end) {
    long long crossProduct = (long long)start.first*end.second - (long long)start.second*end.first;
    if(crossProduct > 0) {
        return 1;
    } else if(crossProduct == 0) {
        return 0;
    } else {
        return -1;
    };
}

bool isOnLine(point a1, point a2, point b) {
    int aMinX, aMaxX, aMinY, aMaxY;
    if(a1.first<a2.first) {
        aMinX = a1.first;
        aMaxX = a2.first;
    } else {
        aMinX = a2.first;
        aMaxX = a1.first;
    }

    if(a1.second<a2.second) {
        aMinY = a1.second;
        aMaxY = a2.second;
    } else {
        aMinY = a2.second;
        aMaxY = a1.second;
    }

    return aMinX<=b.first && aMaxX>=b.first && aMinY<=b.second && aMaxY>=b.second;
}

int main() {
    point a1, a2, b1, b2;

    cin >> a1.first >> a1.second >> a2.first >> a2.second >> b1.first >> b1.second >> b2.first >> b2.second;

    int aToB1, aToB2, bToA1, bToA2;

    aToB1 = getCCW(getVector(a1, a2), getVector(a2, b1));    
    aToB2 = getCCW(getVector(a1, a2), getVector(a2, b2));    
    bToA1 = getCCW(getVector(b1, b2), getVector(b2, a1));    
    bToA2 = getCCW(getVector(b1, b2), getVector(b2, a2));    

    if(aToB1==0 && isOnLine(a1, a2, b1) ||
    aToB2==0 && isOnLine(a1, a2, b2) ||
    bToA1==0 && isOnLine(b1, b2, a1) ||
    bToA2==0 && isOnLine(b1, b2, a2)) {
        cout << "1";
    } else if (aToB1*aToB2==-1 && bToA1*bToA2==-1) {
        cout << "1";
    } else {
        cout << "0";
    }

}