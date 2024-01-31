#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<pair<int, int> > > adjacentVector;
int v; 

pair<int, int> DFS(int start) {

    pair<int, int> farLeaf = {0,0};

    stack<pair<int, int> > st;
    vector<bool> isVisited(v+1, false);

    st.push({start, 0});

    while(!st.empty()) {
        pair<int, int> topP = st.top();
        st.pop();
        isVisited[topP.first] = true;

        if(topP.second > farLeaf.second) {
            farLeaf = topP;
        }

        for(auto node: adjacentVector[topP.first]) {
            if(!isVisited[node.first]) {
                st.push({node.first, topP.second+node.second});
            }
        }
    }

    return farLeaf;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> v;

    adjacentVector = vector<vector<pair<int, int> > >(v+1);

    for(int i=0; i<v; i++) {
        int startVertex;
        int targetVertex, dist;
        cin >> startVertex >> targetVertex;

        while(targetVertex!=-1) {
            cin >> dist;
            adjacentVector[startVertex].push_back({targetVertex, dist});
            cin >> targetVertex;
        }
    }

    int farLeaf = DFS(1).first;

    cout << DFS(farLeaf).second;

}