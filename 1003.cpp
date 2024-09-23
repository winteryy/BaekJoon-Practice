#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<pair<int, int> > fiboList(41);

    fiboList[0] = { 1, 0 };
    fiboList[1] = { 0, 1 };

    for(int i=2; i<=40; i++) {
        fiboList[i] = { fiboList[i-1].first + fiboList[i-2].first, fiboList[i-1].second + fiboList[i-2].second };
    }

    int t, num;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> num;
        cout << fiboList[num].first << " " << fiboList[num].second << "\n";
    }

}