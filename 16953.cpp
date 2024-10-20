#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    queue<pair<int, int> > q;
    q.push({a, 1});

    unordered_set<int> isVisited;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        auto pos = isVisited.find(cur.first);
        if(pos != isVisited.end()) continue;
        if(cur.first == b) {
            cout << cur.second;
            return 0;
        }

        isVisited.insert(cur.first);

        long long next = (long long)cur.first * 2;
        if(next<=b) q.push({next, cur.second+1});
        next = (long long)cur.first*10 + 1;
        if(next<=b) q.push({next, cur.second+1});
    }

    cout << "-1";
}