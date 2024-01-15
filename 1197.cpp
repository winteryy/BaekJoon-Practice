#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Edge{
public:
    int n1, n2, cost;

    Edge(int v1, int v2, int c) {
        if(v1<v2) {
            n1 = v1;
            n2 = v2;
        }else {
            n1 = v2;
            n2 = v1;
        }
        cost = c;
    }

    bool operator <(Edge other) const{
        return this->cost > other.cost;
    } 
};

vector<int> roots;

int getRoot(int n) {
    if(roots[n]==n) {
        return n;
    }else {
        roots[n]=getRoot(roots[n]);
        return roots[n];
    }
}

void unionRoot(int a, int b) {
    int rootA = getRoot(a);
    int rootB = getRoot(b);

    if(rootA<rootB) {
        roots[rootB] = rootA;
    }else if(rootA>rootB) {
        roots[rootA] = rootB;
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    priority_queue<Edge> pq;
    roots.push_back(0);
    for(int i=1; i<=v; i++) {
        roots.push_back(i);
    }

    for(int i=0; i<e; i++) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        pq.push(Edge(v1, v2, c));
    }

    int edgeNum=0;
    long costSum=0;

    while(!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        if(getRoot(cur.n1) != getRoot(cur.n2)) {
            unionRoot(cur.n1, cur.n2);
            costSum += cur.cost;
            edgeNum++;
        }

        if(edgeNum == v-1) {
            break;
        }

    }

    cout << costSum;
}