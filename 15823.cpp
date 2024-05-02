#include <iostream>
#include <vector>

using namespace std;

vector<int> cards;
int n, m;

bool checkAvail(int num) {
    vector<int> lastInd(500001, -1);
    int count = 0;
    int start=0, end=0;

    while(end<n) {
        if(lastInd[cards[end]]>=start) {
            start = lastInd[cards[end]] + 1;
        }
        lastInd[cards[end]] = end;
        
        if(end-start+1==num) {
            count++;
            start=end+1;
        }

        if(count==m) {
            return true;
        }
        end++;
    }

    return false;
}

int binarySearch(int start, int end) {
    int mid = (start+end+1)/2;

    if(start==mid) return start;
    if(checkAvail(mid)) {
        return binarySearch(mid, end);
    }else {
        return binarySearch(start, mid-1);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    cards = vector<int>(n);
    for(int i=0; i<n; i++) {
        cin >> cards[i];
    }

    cout << binarySearch(1, n);
}