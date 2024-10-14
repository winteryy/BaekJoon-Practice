#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1'000'000'007

using namespace std;

vector<long long> segTree;
vector<long long> arr;

long long makeTree(int l, int r, int ind) {
    if(l==r) {
        segTree[ind] = arr[l];
        return segTree[ind];
    } else {
        int mid = (l+r)/2;
        segTree[ind] = makeTree(l, mid, ind*2) * makeTree(mid+1, r, ind*2+1) % MOD;
        return segTree[ind];
    }
}

long long getMulti(int l, int r, int ind, int lBound, int rBound) {
    if(l>rBound || r<lBound) return 1;
    if(l>=lBound && r<=rBound) return segTree[ind];

    int mid = (l+r)/2;
    return getMulti(l, mid, ind*2, lBound, rBound) * getMulti(mid+1, r, ind*2+1, lBound, rBound) % MOD;
}

long long update(int l, int r, int ind, int target, int newNum) {
    if(target<l || target>r) return segTree[ind];
    if(l==r) return segTree[ind] = newNum;
    
    int mid = (l+r)/2;
    return segTree[ind] = update(l, mid, ind*2, target, newNum) * update(mid+1, r, ind*2+1, target, newNum) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    segTree = vector<long long>(n*4);
    arr = vector<long long>(n+1);

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    makeTree(1, n, 1);

    int a, b, c;
    for(int i=0; i<m+k; i++) {
        cin >> a >> b >> c;
        if(a==1) {
            update(1, n, 1, b, c);
            arr[b] = c;
        } else {
            cout << getMulti(1, n, 1, b, c) << "\n";
        }
    }
}