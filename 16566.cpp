#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cardVector(m);
    int num;

    for(int i=0; i<m; i++) {
        cin >> cardVector[i];
    }

    sort(cardVector.begin(), cardVector.end());

    set<int> cardSet(cardVector.begin(), cardVector.end());

    for(int i=0; i<k; i++) {
        cin >> num;

        auto ub = cardSet.upper_bound(num);
        cout << *ub << "\n";
        cardSet.erase(ub);
    }
}