#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;


    for(int i=0; i<t; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> aVector(a);
        vector<int> bVector(b);

        for(int j=0; j<a; j++) {
            cin >> aVector[j];
        }
        for(int j=0; j<b; j++) {
            cin >> bVector[j];
        }

        sort(aVector.begin(), aVector.end());
        sort(bVector.begin(), bVector.end());

        int cnt = 0;
        for(int j=0; j<a; j++) {
            cnt += lower_bound(bVector.begin(), bVector.end(), aVector[j]) - bVector.begin();
        }
        cout << cnt << "\n";
    }
}