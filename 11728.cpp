#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<m; i++) {
        cin >> b[i];
    }

    int i=0, j=0;
    vector<int> ans;
    while(i<=n && j<=m) {
        if(i==n) {
            for(j; j<m; j++) {
                ans.push_back(b[j]);
            }
            break;
        }else if(j==m) {
            for(i; i<n; i++) {
                ans.push_back(a[i]);
            }
            break;
        }else {
            if(a[i]<=b[j]) {
                ans.push_back(a[i]);
                i++;
            }else {
                ans.push_back(b[j]);
                j++;
            }
        }
    }

    for(auto num: ans) {
        cout << num << " ";
    }
 
}