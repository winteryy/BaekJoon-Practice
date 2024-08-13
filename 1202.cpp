#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 

int n, k;
pair<int, int> gemList[300000];
int bagList[300000];

int main() {
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> gemList[i].first >> gemList[i].second;
    }

    for(int i=0; i<k; i++) {
        cin >> bagList[i];
    }

    priority_queue<int> pq;
    sort(gemList, gemList+n);
    sort(bagList, bagList+k);
    long long sum = 0;
    int gemInd = 0;
    for(int i=0; i<k; i++) {
        int bag = bagList[i];
        while(gemInd<n && gemList[gemInd].first<=bag) {
            pq.push(gemList[gemInd].second);
            gemInd++;
        }

        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;
}