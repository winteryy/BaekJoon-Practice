#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class DistInfo {
    public:
    
    int vertexNum, dist, dfsDist;

    DistInfo(int vNum, int d) {
        vertexNum = vNum;
        dist = d;
        dfsDist = 0;
    }
};

class Node {
    public:
    
    vector<DistInfo> dists;
};

int main() {
    int v; 
    cin >> v;

    vector<Node> nodes(v+1, Node());

    for(int i=1; i<=v; i++) {
        int vertexNum;
        cin >> vertexNum >> vertexNum;
        while(vertexNum!=-1) {
            int dist;
            cin >> dist;

            nodes[i].dists.push_back(DistInfo(vertexNum, dist));

            cin >> vertexNum;
        }
    }

    for(int i=1; i<=v; i++) {

        for(int j=0; j<nodes[i].dists.size(); j++) {
            vector<bool> visited(v+1, false);
            visited[i] = true;
            stack<int> s;
            s.push(nodes[i].dists[j].vertexNum);

            int distSum = nodes[i].dists[j].dist;

            while(!s.empty()) {
                
            }

        }

    }
}