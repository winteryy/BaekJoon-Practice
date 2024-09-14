#include <iostream> 
#include <vector>

using namespace std;

vector<int> root;

int find(int x) {
    if(root[x]==x) {
        return x;
    } else {
        root[x] = find(root[x]);
        return root[x];
    }
}

bool makeUnion(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if(rootX==rootY) return false;

    if(rootX<rootY) {
        root[rootY] = rootX;
    } else {
        root[rootX] = rootY;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    root = vector<int>(n);
    for(int i=0; i<n; i++) {
        root[i] = i;
    }

    int cycleOccur = 0;
    int p1, p2;
    for(int i=0; i<m; i++) {
        cin >> p1 >> p2;
        if(cycleOccur!=0) continue;
        if(!makeUnion(p1, p2)) {
            cycleOccur = i+1;
        }
    }

    cout << cycleOccur;
}