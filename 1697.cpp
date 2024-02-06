#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<bool> isVisited(100001, false);

bool isValid(int x) {
    return x>=0 && x<=100000;
}

int main() {
    int n, k;
    cin >> n >> k;
    queue<pair<int, int> > q;
    q.push({n, 0});

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if(isVisited[cur.first]) continue;

        isVisited[cur.first] = true;

        if(cur.first==k) {
            cout << cur.second;
            break;
        }

        if(isValid(cur.first+1) && !isVisited[cur.first+1]) q.push({cur.first+1, cur.second+1});
        if(isValid(cur.first-1) && !isVisited[cur.first-1]) q.push({cur.first-1, cur.second+1});
        if(isValid(cur.first*2) && !isVisited[cur.first*2]) q.push({cur.first*2, cur.second+1});
    }

}