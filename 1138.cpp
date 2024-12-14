#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> order(n, 0);

    for(int i=1; i<=n; i++) {
        int num;
        cin >> num;

        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(order[j]==0) {
                if(cnt==num) {
                    order[j] = i;
                    break;
                } else {
                    cnt++;
                }
            }
        }
    }

    for(int num: order) {
        cout << num << " ";
    }
}