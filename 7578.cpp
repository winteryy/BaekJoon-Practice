#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> segTree;
vector<int> dest;

long long search(const int l, const int r, const int lBound, const int rBound, const int ind) {
    if(r<lBound || l>rBound) return 0;
    if(r<=rBound && l>=lBound) return segTree[ind];

    int mid = (l+r)/2;
    return search(l, mid, lBound, rBound, ind*2) + search(mid+1, r, lBound, rBound, ind*2+1);
}

void update(const int l, const int r, const int target, const int ind) {
    if(r<target || l>target) return;
    segTree[ind]++;
    if(l==r) return;

    int mid = (l+r)/2;
    update(l, mid, target, ind*2);
    update(mid+1, r, target, ind*2+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    segTree = vector<int>(n*4, 0);
    dest = vector<int>(1000001);
    
    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        dest[num] = i;
    }

    long long ans = 0;
    for(int i=0; i<n; i++) {
        cin >> num;
        update(0, n-1, dest[num], 1);
        ans += search(0, n-1, dest[num]+1, n-1, 1);
    }

    cout << ans;
}