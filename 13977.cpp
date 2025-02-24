#include <iostream>
#include <map>
#include <vector>
#define MOD 1000000007

using namespace std;

vector<map<int, int> > calculated; 

int bi_co(const int n, const int k) {
    if(n==k || k==0) return 1;

    auto iter = calculated[n].find(k);
    if(iter != calculated[n].end()) {
        return iter->second;
    }

    int value = (bi_co(n-1, k-1) + bi_co(n-1, k)) % MOD;
    calculated[n].insert({k, value});
    calculated[n].insert({k, value});
    return value;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n, k;
    cin >> m;
    calculated = vector<map<int, int> >(4000001);

    while(m--) {
        cin >> n >> k;

        cout << bi_co(n, k) << "\n";
    }
}