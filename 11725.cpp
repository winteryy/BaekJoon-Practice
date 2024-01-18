#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Vertex {
public:
    vector<int> edges;

    Vertex() {
        edges = vector<int>();
    }

    void insert(int num) {
        edges.push_back(num);
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, v1, v2;
    cin >> n;

    vector<Vertex> vertexArr(n+1, Vertex());

    for(int i=0; i<n-1; i++) {
        cin >> v1 >> v2;
        vertexArr[v1].insert(v2);
        vertexArr[v2].insert(v1);
    }

    vector<int> parent(n+1, 0);
    queue<int> q;

    for(int i=0; i<vertexArr[1].edges.size(); i++) {
        parent[vertexArr[1].edges[i]] = 1;
        q.push(vertexArr[1].edges[i]);
    }

    while(!q.empty()) {
        int cur = q.front();
        for(int i=0; i<vertexArr[cur].edges.size(); i++) {
            int searchV = vertexArr[cur].edges[i];
            if(searchV!=parent[cur]) {
                parent[searchV] = cur;
                q.push(searchV);
            }
        }
        q.pop();
    }

    for(int i=2; i<=n; i++) {
        cout << parent[i] << "\n";
    }
} 