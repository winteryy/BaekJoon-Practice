#include <iostream>
#include <vector>

using namespace std;

int main() {

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q, start, end;
    cin >> n >> q;
    vector<int> numVector(n+1, 0);
    vector<int> accXor(n+1, 0);
    vector<int> resultXor;

    for(int i=1; i<=n; i++) {
        cin >> numVector[i];
        accXor[i] = numVector[i]^accXor[i-1];
    }

    for(int i=0; i<q; i++) {
        cin >> start >> end;
        resultXor.push_back(accXor[start-1]^accXor[end]);
    }

    int result = 0;
    
    for(int e: resultXor) {
        result ^= e;
    }

    cout << result;

}