#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int num;

    auto cmp = [](const int& l, const int& r) {
        if(abs(l)==abs(r)) {
            return l>r;
        } else {
            return abs(l)>abs(r);
        }
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    while(n--) {
        cin >> num;
        if(num==0) {
            if(pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(num);
        }
    }
    
}