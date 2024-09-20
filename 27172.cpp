#include <iostream>

using namespace std;

int indList[1000001];
int numList[100001];
int scoreList[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> numList[i];
        indList[numList[i]] = i;
    }

    for(int i=1; i<=n; i++) {
        int num = numList[i];
        for(int j=2; j*num<=1000000; j++) {
            if(indList[j*num]!=0) {
                scoreList[i]++;
                scoreList[indList[j*num]]--;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << scoreList[i] << " ";
    }

}