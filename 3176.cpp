#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int sparseTable[100001][18][3]; // {nodeNum, max, min}
int depthArr[100001];
vector<vector<pair<int, int> > > dist;
int n, depth;

void initSparseTable() {
    vector<bool> isVisited(n + 1, false);
    stack<pair<int, int> > st;
    st.push({ 1, 1 });

    while (!st.empty()) {
        int curNode = st.top().first;
        int curDepth = st.top().second;
        st.pop();

        if (isVisited[curNode]) continue;
        isVisited[curNode] = true;
        depthArr[curNode] = curDepth;

        for (auto edge : dist[curNode]) {
            if (!isVisited[edge.first]) {
                st.push({ edge.first, curDepth + 1 });
                sparseTable[edge.first][0][0] = curNode;
                sparseTable[edge.first][0][1] = sparseTable[edge.first][0][2] = edge.second;
            }
        }
    }
}

void makeSparseTable() {
    initSparseTable();

    depth = log2(n) + 1;
    for (int i = 1; i <= depth; i++) {
        for (int j = 1; j <= n; j++) { // 탐색 기준 노드
            int parent = sparseTable[j][i - 1][0];
            int anc = sparseTable[parent][i - 1][0];
            sparseTable[j][i][0] = anc;

            if (anc == 0) continue;

            int parentMax = sparseTable[j][i - 1][1];
            int parentMin = sparseTable[j][i - 1][2];

            int ancMax = sparseTable[parent][i - 1][1];
            int ancMin = sparseTable[parent][i - 1][2];

            sparseTable[j][i][1] = max(parentMax, ancMax);
            sparseTable[j][i][2] = min(parentMin, ancMin);
        }
    }
}

pair<int, int> query(int v1, int v2) {
    if (depthArr[v1] < depthArr[v2]) {
        swap(v1, v2);
    }
    int maxCost = 0;
    int minCost = 987654321;

    for (int i = depth; i >= 0; i--) {
        if (depthArr[v1] - depthArr[v2] >= (1 << i)) {
            maxCost = max(sparseTable[v1][i][1], maxCost);
            minCost = min(sparseTable[v1][i][2], minCost);

            v1 = sparseTable[v1][i][0];
        }
    }

    if (v1 == v2) {
        return { maxCost, minCost };
    }

    for (int i = depth; i >= 0; i--) {
        if (sparseTable[v1][i][0] != sparseTable[v2][i][0]) {
            maxCost = max(max(sparseTable[v1][i][1], sparseTable[v2][i][1]), maxCost);
            minCost = min(min(sparseTable[v1][i][2], sparseTable[v2][i][2]), minCost);

            v1 = sparseTable[v1][i][0];
            v2 = sparseTable[v2][i][0];
        }
    }
    maxCost = max(max(sparseTable[v1][0][1], sparseTable[v2][0][1]), maxCost);
    minCost = min(min(sparseTable[v1][0][2], sparseTable[v2][0][2]), minCost);

    return { maxCost, minCost };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    dist = vector<vector<pair<int, int> > >(n + 1);
    int v1, v2, c, k;
    for (int i = 0; i < n-1; i++) {
        cin >> v1 >> v2 >> c;

        dist[v1].push_back({ v2, c });
        dist[v2].push_back({ v1, c });
    }

    makeSparseTable();

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> v1 >> v2;
        auto result = query(v1, v2);

        cout << result.second << " " << result.first << "\n";
    }

}