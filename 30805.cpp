#include <iostream>

using namespace std;

int arrA[101];
int arrB[101];
int lcs[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arrA[i];
    }
    cin >> m;
    for(int i=1; i<=m; i++) {
        cin >> arrB[i];
    }

    lcs[0] = 0;
    int lcsInd = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(arrA[i]==arrB[j]) {
                if(lcsInd==0) {
                    lcs[1] = j;
                    lcsInd = 1;
                    break;
                } else {
                    int pos = lcsInd+1;
                    for(int k=1; k<=lcsInd; k++) {
                        if(arrB[lcs[k]]<arrA[i] && lcs[k-1]<j) {
                            pos = k;
                            break;
                        }
                    }
                    if((pos==lcsInd+1 && lcs[lcsInd]<j) || pos!=lcsInd+1) {
                        lcs[pos] = j;
                        lcsInd = pos;
                        break;
                    }
                }
            }
        }
    }

    cout << lcsInd << "\n";
    for(int i=1; i<=lcsInd; i++) {
        cout << arrB[lcs[i]] << " ";
    }
}