#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, n;
    cin >> w >> n;

    vector<int> numArr(n);
    for(int i=0; i<n; i++) {
        cin >> numArr[i];
    }

    vector<pair<int, int> > selectTwoElement(w+1, {-1,-1});
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(numArr[i]+numArr[j]<=w) {
                selectTwoElement[numArr[i]+numArr[j]]={i, j};
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int weight = w - (numArr[i]+numArr[j]);
            if(weight>=0 && weight<=w && selectTwoElement[weight].first!=-1) {
                if(i == selectTwoElement[weight].first || i == selectTwoElement[weight].second 
                    || j == selectTwoElement[weight].first || j == selectTwoElement[weight].second) continue;
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}