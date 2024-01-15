#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, d, k, c;
    int totalDiverse = 0;
    cin >> n >> d >> k >> c;

    vector<int> rail(n);
    vector<int> sushiCount(d+1, 0);
    sushiCount[c]++;
    totalDiverse++;

    for(int i=0; i<n; i++) {
        cin >> rail[i];
    }

    for(int i=0; i<k; i++) {
        if(sushiCount[rail[i]]==0) {
            totalDiverse++;
        }
        sushiCount[rail[i]]++;
    }

    int maxDiverse = 0;
    int l=0, r=k-1;

    while(l<n) {
        maxDiverse = max(maxDiverse, totalDiverse);

        if(sushiCount[rail[l]]==1) {
            totalDiverse--;
        }
        sushiCount[rail[l]]--;
        l++;
        r++;
        if(sushiCount[rail[r%n]]==0) {
            totalDiverse++;
        }
        sushiCount[rail[r%n]]++;
    }

    cout << maxDiverse;
}