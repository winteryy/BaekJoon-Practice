#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> nameNum(21, 0);

    queue<int> q;
    string s;
    long long result = 0;
    for(int i=0; i<n; i++) {
        cin >> s;
        int nameLen = s.size();
        if(q.size()>k) {
            nameNum[q.front()]--;
            q.pop();
        }
        result += nameNum[nameLen];
        q.push(nameLen);
        nameNum[nameLen]++;
    }

    cout << result;
    return 0;
}