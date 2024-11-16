#include <iostream>
#include <algorithm>

using namespace std; 

int selectedFruit[10];
int fruitList[200000];

bool isValid() {
    int count = 0;
    for(int i=1; i<10; i++) {
        if(selectedFruit[i]>0) count++;
    }

    return count<=2;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> fruitList[i];
    }

    for(int i=1; i<10; i++) {
        selectedFruit[i] = 0;
    }

    int l=0, r=0;
    int maxLength=0;
    while(r<n && l<n) {
        selectedFruit[fruitList[r]]++;

        while(!isValid()) {
            selectedFruit[fruitList[l]]--;
            l++;
        }
        
        maxLength = max(maxLength, r-l+1);
        r++;
    }

    cout << maxLength;
}