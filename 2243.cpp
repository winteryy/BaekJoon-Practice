#include <iostream>

using namespace std;

const int MAX_FAV = 1000000;
long long segTree[MAX_FAV * 4] = {0,};
int n;

int query(int l, int r, int ind, int cnt) {
    segTree[ind]--;
    if(l==r) return l;
    int mid = (l+r)/2;
    if(segTree[ind*2] >= cnt) {
        return query(l, mid, ind*2, cnt);
    } else {
        return query(mid+1, r, ind*2+1, cnt-segTree[ind*2]);
    }
}

void updateTree(int l, int r, int ind, int target, long long delta) {
    if(target<l || target>r) return;
    segTree[ind] += delta;
    if(l==r) {
        return;
    } else {
        int mid = (l+r)/2;
        updateTree(l, mid, ind*2, target, delta);
        updateTree(mid+1, r, ind*2+1, target, delta);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int a, b, c;    

    while(n--) {
        cin >> a >> b;
        if(a==1) {
            int ans = query(1, MAX_FAV, 1, b);
            cout << ans << "\n";
            // updateTree(1, MAX_FAV, 1, ans, -1);
        } else {
            cin >> c;
            updateTree(1, MAX_FAV, 1, b, c);
        }
    }
}