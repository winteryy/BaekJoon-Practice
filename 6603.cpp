#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
vector<int> ans;
int n;

void comb(int prev, int current) {
    if(current==6) {
        for(auto num: ans) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }else {
        for(int i=prev+1; i<=n; i++) {
            ans.push_back(v[i]);
            comb(i, current+1);
            ans.pop_back();
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int num;
    cin >> n;

    while(n!=0) {
        v = vector<int> (n+1, 0);
        for(int i=1; i<=n; i++) {
            cin >> v[i];
        }

        comb(0, 0);
        cout << "\n";

        cin >> n;
    }
}