#include <iostream>
#include <queue>
#include <vector>
#define MAX_SEC 987654321

using namespace std;

vector<int> isVisited(100001, -1);

bool isValid(int x) {
    return x>=0 && x<=100000;
}

int main() {
    int n, k;
    cin >> n >> k;
    queue<pair<int, int> > q;
    q.push({n, 0});

    int minSec = MAX_SEC;
    int minCount = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if(minSec!=MAX_SEC) {
            if(cur.second>minSec) {
                continue;
            }else if(cur.first==k) {
                minCount++;
                continue;
            }
        }

        if(isVisited[cur.first]==-1) { 
            isVisited[cur.first] = cur.second;
        }else if(isVisited[cur.first]<cur.second) {
            continue;
        }

        if(cur.first==k) {
            minSec = cur.second;
            continue;
        }

        if(isValid(cur.first+1)) q.push({cur.first+1, cur.second+1});
        if(isValid(cur.first-1)) q.push({cur.first-1, cur.second+1});
        if(isValid(cur.first*2)) q.push({cur.first*2, cur.second+1});
    }

    cout << minSec << "\n" << minCount;

}