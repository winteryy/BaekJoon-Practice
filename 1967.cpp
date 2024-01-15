#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    bool isLeaf;
    pair<int, int> parent;
    vector<pair<int, int> > children;

    Node() {
        isLeaf = true;
        parent = make_pair(-1, -1);
    }
};

int main() {
    int n;
    cin >> n;
    if(n==1) {
        cout << "0";
        return 0;
    }

    vector<Node> nodes(n+1, Node());
    vector<int> leaves;
    while(true) {
        int u, v, w;
        cin >> u >> v >> w;

        nodes[u].isLeaf = false;
        nodes[u].children.push_back(make_pair(v, w));
        nodes[v].parent.first = u;
        nodes[v].parent.second = w;

        if(cin.eof()) {
            break;
        }
    }

    for(int i=1; i<=n; i++) {
        if(nodes[i].isLeaf) {
            leaves.push_back(i);
        }
    }

    int maxDist = 0;
    for(int i=0; i<leaves.size(); i++) {
        stack<pair<int, int>> s;
        vector<bool> visited(n+1, false);
        s.push(make_pair(leaves[i], 0));

        while(!s.empty()) {
            pair<int, int> p = s.top();
            s.pop();

            visited[p.first] = true;
            Node now = nodes[p.first];
            if(now.parent.first!=-1 && !visited[now.parent.first]) {
                if(now.parent.first==1) {
                    maxDist = max(maxDist, p.second+now.parent.second);
                }
                s.push(make_pair(now.parent.first, p.second+now.parent.second));
            }
            for(int j=0; j<now.children.size(); j++) {
                if(!visited[now.children[j].first]) {
                    if(nodes[now.children[j].first].isLeaf) {
                        maxDist = max(maxDist, p.second+now.children[j].second);
                    }else {
                        s.push(make_pair(now.children[j].first, p.second+now.children[j].second));
                    }
                }
            }
        }
    }

    cout << maxDist;
}