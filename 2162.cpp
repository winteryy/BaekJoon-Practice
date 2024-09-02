#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> point;
typedef pair<int, int> vec;

int root[3000]; 

int find(int x) {
    if(root[x]==x) {
        return x;
    } else {
        root[x] = find(root[x]);
        return root[x];
    }
}

void makeUnion(int x, int y) {
    x = find(x);
    y = find(y);

    if(x<=y) {
        root[y] = x;
    } else {
        root[x] = y;
    }
}

vec getVector(point start, point end) {
    return {end.first - start.first, end.second - start.second};
}

int getCCW(vec start, vec end) {
    int crossProduct = start.first*end.second - start.second*end.first;
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        root[i] = i;
    }

    vector<pair<point, point> > lineList;
    point p1, p2;

    for(int i=0; i<n; i++) {
        cin >> p1.first >> p1.second >> p2.first >> p2.second;

        for(int j=0; j<lineList.size(); j++) {
            pair<point, point> t = lineList[j];
            int pToT1, pToT2, tToP1, tToP2;

            pToT1 = getCCW(getVector(p1, p2), getVector(p2, t.first));    
            pToT2 = getCCW(getVector(p1, p2), getVector(p2, t.second));    
            tToP1 = getCCW(getVector(t.first, t.second), getVector(t.second, p1));    
            tToP2 = getCCW(getVector(t.first, t.second), getVector(t.second, p2));    

            if(pToT1==0 && isOnLine(p1, p2, t.first) ||
            pToT2==0 && isOnLine(p1, p2, t.second) ||
            tToP1==0 && isOnLine(t.first, t.second, p1) ||
            tToP2==0 && isOnLine(t.first, t.second, p2)) {
                makeUnion(i, j);
            } else if (pToT1*pToT2==-1 && tToP1*tToP2==-1) {
                makeUnion(i, j);
            }
        }

        lineList.push_back({p1, p2});
    }

    unordered_map<int, int> numTable;

    int rootNum, maxNum = 0;
    for(int i=0; i<n; i++) {
        rootNum = find(i);

        numTable[rootNum]++;
    }
    
    for(auto p: numTable) {
        maxNum = max(maxNum, p.second);
    }
    cout << numTable.size() << "\n" << maxNum;

}