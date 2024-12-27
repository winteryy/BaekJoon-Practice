#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> roots;

int getRoot(int n) {
    if(roots[n]==n) return n;

    return roots[n] = getRoot(roots[n]);
}

void makeUnion(int x, int y) {
    int rootX = getRoot(x);
    int rootY = getRoot(y);

    if(rootX<rootY) {
        roots[rootY] = rootX;
    } else {
        roots[rootX] = rootY;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    int cmd, a, b;
    cin >> n >> m;

    roots = vector<int>(n+1);
    generate(roots.begin(), roots.end(), [i=0]() mutable { return i++; });

    while(m--) {
        cin >> cmd >> a >> b;

        if(cmd==0) {
            makeUnion(a, b);
        } else {
            if(getRoot(a)==getRoot(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}