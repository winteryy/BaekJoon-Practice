#include <iostream>
#include <vector>

using namespace std;

vector<long long> arrSumTree;
vector<long long> numArr;

long long makeTree(int l, int r, int ind) {
    if(l==r) {
        arrSumTree[ind] = numArr[l];
        return arrSumTree[ind];
    } else {
        int mid = (l+r)/2;
        arrSumTree[ind] = makeTree(l, mid, ind*2) + makeTree(mid+1, r, ind*2+1);
        return arrSumTree[ind];
    }
}

long long getArrSum(int l, int r, int ind, int lBound, int rBound) {
    if(l>rBound || r<lBound) return 0;
    if(l>=lBound && r<=rBound) return arrSumTree[ind];
    int mid = (l+r)/2;
    return getArrSum(l, mid, ind*2, lBound, rBound) + getArrSum(mid+1, r, ind*2+1, lBound, rBound);
}

void updateTree(int l, int r, int ind, int target, long long delta) {
    if(target<l || target>r) return;
    arrSumTree[ind] += delta;
    if(l==r) {
        return; 
    } else {
        int mid = (l+r)/2;
        updateTree(l, mid, ind*2, target, delta);
        updateTree(mid+1, r, ind*2+1, target, delta);
    }
}

void initSize(int n) {
    arrSumTree = vector<long long>(n*4);
    numArr = vector<long long> (n+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    initSize(n);

    for(int i=1; i<=n; i++) {
        cin >> numArr[i];
    }

    makeTree(1, n, 1);

    int a, b;
    long long c;

    for(int i=0; i<m+k; i++) {
        cin >> a >> b >> c;
        if(a==1) {
            updateTree(1, n, 1, b, c-numArr[b]);
            numArr[b] = c;
        } else {
            cout << getArrSum(1, n, 1, b, c) << "\n";
        }
    }
}