#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001

using namespace std;

vector<pair<int, int> > minMaxTree(401000, {INF, 0}); // {min, max}
vector<int> numArr;

pair<int, int> makeTree(int l, int r, int ind) {
    if(l==r) {
        minMaxTree[ind] = {numArr[l], numArr[l]};
        return minMaxTree[ind];
    } else {
        int mid = (l+r)/2;
        pair<int, int> leftChild = makeTree(l, mid, ind*2);
        pair<int, int> rightChild = makeTree(mid+1, r, ind*2+1);
        minMaxTree[ind] = {min(leftChild.first, rightChild.first), max(leftChild.second, rightChild.second)};
        return minMaxTree[ind];
    }
}

pair<int, int> getMinMax(int l, int r, int ind, int lBound, int rBound) {
    if(l > rBound || r < lBound) return {INF, 0};
    if(l >= lBound && r <= rBound) return minMaxTree[ind];
    int mid = (l+r)/2;
    pair<int, int> leftMinMax = getMinMax(l, mid, ind*2, lBound, rBound);
    pair<int, int> rightMinMax = getMinMax(mid+1, r, ind*2+1, lBound, rBound);
    return {min(leftMinMax.first, rightMinMax.first), max(leftMinMax.second, rightMinMax.second)};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    numArr = vector<int>(n+1);
    for(int i=1; i<=n; i++) {
        cin >> numArr[i];
    }

    makeTree(1, n, 1);

    int left, right;
    for(int i=0; i<m; i++) {
        cin >> left >> right;
        pair<int, int> result = getMinMax(1, n, 1, left, right);
        cout << result.first << " " << result.second << "\n";
    }

}