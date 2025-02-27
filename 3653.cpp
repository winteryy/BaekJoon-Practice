#include <iostream>
#include <vector>

using namespace std;

vector<int> segTree;
vector<int> indArr;

int search(const int l, const int r, const int lBound, const int rBound, const int ind) {
    if(l>rBound || r<lBound) return 0;
    if(l>=lBound && r<=rBound) return segTree[ind];

    int mid = (l+r)/2;
    return search(l, mid, lBound, rBound, ind*2) + search(mid+1, r, lBound, rBound, ind*2+1);
}

void update(const int l, const int r, const int target, const int ind, const bool isAdd) {
    if(l>target || r<target) return;
    
    if(isAdd) {
        segTree[ind]++;
    } else {
        segTree[ind]--;
    }
    if(l==r) return;

    int mid = (l+r)/2;
    update(l, mid, target, ind*2, isAdd);
    update(mid+1, r, target, ind*2+1, isAdd);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, m;

    cin >> t;

    while(t--) {
        cin >> n >> m;
        
        segTree = vector<int>((n+m)*4, 0);
        indArr = vector<int>(n+1);
        int segIndRange = n+m-1;
        for(int i=0; i<n; i++) {
            indArr[i+1] = n-i-1;
            update(0, segIndRange, i, 1, true);
        }

        int movie;
        for(int i=0; i<m; i++) {
            cin >> movie;
            cout << search(0, segIndRange, indArr[movie]+1, segIndRange, 1) << " ";
            update(0, segIndRange, indArr[movie], 1, false);
            update(0, segIndRange, n+i, 1, true);
            indArr[movie] = n+i;
        }
        cout << "\n";
    }
}