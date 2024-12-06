#include <iostream>
#include <vector>
#define INF 1'000'000'001

using namespace std;

vector<int> arr;
vector<pair<int, int> > segTree;

pair<int, int> initTree(int l, int r, int ind) {
    if(l==r) {
        return segTree[ind] = {arr[l], l};
    } else {
        int mid = (l+r)/2;
        auto leftSeg = initTree(l, mid, ind*2);
        auto rightSeg = initTree(mid+1, r, ind*2+1);

        if(leftSeg<rightSeg) {
            return segTree[ind] = leftSeg;
        } else {
            return segTree[ind] = rightSeg;
        }
    }
}

pair<int, int> query(int l, int r, int ind, int lBound, int rBound) {
    if(r<lBound || l>rBound) {
        return {INF, -1};
    } else if(l>=lBound && r<=rBound) {
        return segTree[ind];
    } else {
        int mid = (l+r)/2;
        auto leftSeg = query(l, mid, ind*2, lBound, rBound);
        auto rightSeg = query(mid+1, r, ind*2+1, lBound, rBound);

        if(leftSeg<rightSeg) {
            return leftSeg;
        } else {
            return rightSeg;
        }
    }
}

pair<int, int> update(int l, int r, int ind, int targetInd, int newNum) {
    if(targetInd<l || targetInd>r) {
        return segTree[ind];
    } else if(l==r) {
        return segTree[ind] = {newNum, targetInd};
    } else {
        int mid = (l+r)/2;
        auto leftSeg = update(l, mid, ind*2, targetInd, newNum);
        auto rightSeg = update(mid+1, r, ind*2+1, targetInd, newNum);

        if(leftSeg<rightSeg) {
            return segTree[ind] = leftSeg;
        } else {
            return segTree[ind] = rightSeg;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;
    arr = vector<int>(n+1);
    segTree = vector<pair<int, int> >(n*4);    

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    initTree(1, n, 1);

    cin >> m;

    int cmd, i, j;
    while(m--) {
        cin >> cmd >> i >> j;
        if(cmd==1) {
            update(1, n, 1, i, j);
        } else {
            cout << query(1, n, 1, i, j).second << "\n";
        }
    }
}