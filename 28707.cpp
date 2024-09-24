#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

class Modification {
public:
    int l, r, cost;

    Modification() {
        l = 0;
        r = 0;
        cost = 0;
    }

    Modification(int l, int r, int cost) {
        this->l = l;
        this->r = r;
        this->cost = cost;
    }
};

bool numToBit[8][3] = {
    { false, false, false },
    { false, false, true },
    { false, true, false },
    { false, true, true },
    { true, false, false },
    { true, false, true },
    { true, true, false },
    { true, true, true }
};

vector<int> isVisited(1<<24, INF);

int modifyBit(int origin, int order, bool leftBit, bool midBit, bool rightBit) {
    int newBit = origin;
    if(leftBit) {
        newBit |= 1 << (order*3 + 2);
    } else {
        newBit &= ~(1 << (order*3 + 2));
    }
    if(midBit) {
        newBit |= 1 << (order*3 + 1);
    } else {
        newBit &= ~(1 << (order*3 + 1));
    }
    if(rightBit) {
        newBit |= 1 << (order*3);
    } else {
        newBit &= ~(1 << (order*3));
    }

    return newBit;        
}

int main() {
    int n, m;
    int numArr[8];
    int l, r, c;
    Modification modificationArr[10];

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> numArr[i];
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> l >> r >> c;
        modificationArr[i] = Modification(l-1, r-1, c);
    }

    auto cmp = [](pair<int, int> l, pair<int, int> r) {
        return l.second > r.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> pq(cmp); // {bit, cost}
    int curBit = 0;
    for(int i=0; i<n; i++) {
        curBit = modifyBit(curBit, i, numToBit[i][0], numToBit[i][1], numToBit[i][2]); 
    }
    pq.push({curBit, 0});

    int minCost = INF;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(isVisited[cur.first]<=cur.second) {
            continue;
        }

        isVisited[cur.first] = cur.second;
        bool notDesc = true;
        for(int i=1; i<n; i++) {
            if(numArr[cur.first>>(3*i) & 7] < numArr[cur.first>>(3*(i-1)) & 7]) {
                notDesc = false;
                break;
            }
        }
        if(notDesc) {
            minCost = min(minCost, cur.second);
        } else {
            for(int i=0; i<m; i++) {
                auto md = modificationArr[i];
                bool temp[3] = { cur.first & 1<<(md.l*3+2), cur.first & 1<<(md.l*3+1), cur.first & 1<<(md.l*3) };
                int newBit = modifyBit(cur.first, md.l, cur.first & 1<<(md.r*3+2), cur.first & 1<<(md.r*3+1), cur.first & 1<<(md.r*3));
                newBit = modifyBit(newBit, md.r, temp[0], temp[1], temp[2]);

                if(isVisited[newBit]>cur.second+md.cost) {
                    pq.push({newBit, cur.second + md.cost});
                }
            }
        }

    }
    cout << (minCost==INF?-1:minCost);
}