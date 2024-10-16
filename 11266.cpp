#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int> > adjList;
vector<int> dstNum;
set<int> articulationPointSet;
int dstInd = 0;

int dfs(int num) {
    dstNum[num] = ++dstInd;
    int accessibleHighestNode = dstNum[num];
    int childNum = 0;
 
    for(auto adj: adjList[num]) {
        if(dstNum[adj]>0) { // 이미 방문한 노드
            accessibleHighestNode = min(accessibleHighestNode, dstNum[adj]);
        } else {
            childNum++;
            int highestNodeByChildren = dfs(adj);
            if(dstNum[num] != 1 && highestNodeByChildren >= dstNum[num]) {
                articulationPointSet.insert(num);
            }

            accessibleHighestNode = min(accessibleHighestNode, highestNodeByChildren);
        }
    }

    if(dstNum[num] == 1 && childNum>1) articulationPointSet.insert(num); // DST root 노드, 단절점 확인
    
    return accessibleHighestNode;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    adjList = vector<vector<int> >(v+1);
    dstNum = vector<int>(v+1, 0);

    int start, end;
    for(int i=0; i<e; i++) {
        cin >> start >> end;
        adjList[start].push_back(end);
        adjList[end].push_back(start);
    }

    for(int i=1; i<=v; i++) {
        if(dstNum[i]==0) {
            dstInd = 0;
            dfs(i);
        }
    }

    cout << articulationPointSet.size() << "\n";

    for(int point: articulationPointSet) {
        cout << point << " ";
    }
}