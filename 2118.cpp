#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> distArr(n);
    int totalDist=0;
    for(int i=0; i<n; i++) {
        cin >> distArr[i];
        totalDist+=distArr[i];
    }

    int l=0, r=1;
    int currentDist = distArr[0];
    int maxLength = 0;
    while(r%n!=0) {
        maxLength = max(maxLength, min(currentDist, totalDist-currentDist));
        if(currentDist<totalDist-currentDist) {
            currentDist+=distArr[r%n];
            r++;
        }else {
            currentDist-=distArr[l];
            l++;
        }
    }

    cout << maxLength;
}