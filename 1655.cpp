#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, num;
    cin >> n;
    priority_queue<int> maxPq;
    priority_queue<int, vector<int>, greater<int> > minPq;

    cin >> num;
    maxPq.push(num);
    cout << maxPq.top() << "\n";

    for(int i=1; i<n; i++) {
        cin >> num;
        if(i%2==0) {
            maxPq.push(num);
        }else {
            minPq.push(num);
        }

        if(minPq.top()<maxPq.top()) {
            int temp = maxPq.top();
            maxPq.pop();
            maxPq.push(minPq.top());
            minPq.pop();
            minPq.push(temp);
        }

        cout << maxPq.top() << "\n";
    }

}