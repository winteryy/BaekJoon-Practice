#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adjacentList;
vector<int> subtreeVertexNum;
vector<int> parent;

int getSubNum(int v) {

        int subNum=0;
        for(auto n: adjacentList[v]) {
            if(parent[v]!=n) {
                parent[n] = v;
                subNum+=getSubNum(n);
            }
        }
        
        subNum++;
        subtreeVertexNum[v] = subNum;
        return subNum;
    
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, root, query;
    cin >> n >> root >> query;

    adjacentList = vector<vector<int> >(n+1, vector<int>());
    subtreeVertexNum = vector<int> (n+1, 0);
    parent = vector<int> (n+1, 0);

    for(int i=0; i<n-1; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        adjacentList[v1].push_back(v2);
        adjacentList[v2].push_back(v1);
    }

    getSubNum(root);

    for(int i=0; i<query; i++) {
        cin >> n;
        cout << subtreeVertexNum[n] << "\n";
    }
    
}