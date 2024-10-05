#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int width = 2*n-1;

    for(int i=1; i<=n; i++) {
        int blank = (width-(2*i-1))/2;
        for(int j=0; j<blank; j++) {
            cout << " ";
        }

        if(i%3==1) {
            cout << "*";
        } else {
            cout << "*****";
            

        }
    }
}