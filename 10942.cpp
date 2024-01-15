#include <iostream> 
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, q;
    cin >> n;
    vector<int> numArr(n+1);
    for(int i=1; i<=n; i++) {
        cin >> numArr[i];
    }

    cin >> q;
    vector<pair<int, int> > qPair;
    int s, e;
    for(int i=0; i<q; i++) {
        cin >> s >> e;
        qPair.push_back(make_pair(s, e));
    }

    vector<vector<bool> > ansMatrix(n+1, vector<bool>(n+1, false));

    bool isPal = true;
    for(int i=1; i<=n; i++) {
        int l=i, r=i;
        while(l>=1&&r<=n) {
            if(numArr[l]!=numArr[r]) {
                break;
            }else {
                ansMatrix[l][r] = true;
                l--;
                r++;
            }
        }
    }

    for(int i=1; i<n; i++) {
        int l=i, r=i+1;
        while(l>=1&&r<=n) {
            if(numArr[l]!=numArr[r]) {
                break;
            }else {
                ansMatrix[l][r] = true;
                l--;
                r++;
            }
        }
    }

    for(auto que: qPair) {
        cout << ansMatrix[que.first][que.second] << "\n";
    }

}