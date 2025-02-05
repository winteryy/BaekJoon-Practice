#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int v, e;
vector<vector<int> > graph; 
vector<int> discover;
set<pair<int, int> > answers;

int dfs(int depth, int curNode, int parent) {
    discover[curNode] = depth;

    int childMinDiscover = depth+1;

    for(auto adj: graph[curNode]) {
        if(adj!=parent) {
            if(discover[adj]==-1) {
                childMinDiscover = min(childMinDiscover, dfs(depth+1, adj, curNode));
            } else {
                childMinDiscover = min(childMinDiscover, discover[adj]);
            }
        }
    }

    if(childMinDiscover >= depth && curNode != 1) {
        answers.insert({min(curNode, parent), max(curNode, parent)});
    }

    return childMinDiscover;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e;
    graph = vector<vector<int> >(v+1, vector<int>());
    discover = vector<int>(v+1, -1);

    int a, b;
    for(int i=0; i<e; i++) {
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, 1, 1);
    cout << answers.size() << "\n";
    for(auto ans: answers) {
        cout << ans.first << " " << ans.second << "\n";
    }
}