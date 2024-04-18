#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 3, 0, -3};

int h(const string* s) {
    int score = 0;
    for(int i=0; i<8; i++) {
        if((*s)[i]=='1'+i) {
            score++;
        }
    }
    if((*s)[8]=='0') {
        score++;
    }

    return score;
}

int main() {
    string matrix;
    for(int i=0; i<9; i++) {
        char c;
        cin >> c;
        matrix.push_back(c);
    }

    priority_queue<pair<int, string> > pq;
    unordered_set<string> isVisited;
    pq.push({-h(&matrix), matrix});

    while(!pq.empty()) {
        int hScore = h(&pq.top().second);
        int gScore = -pq.top().first-hScore;
        string curMatrix = pq.top().second;
        pq.pop();

        if(isVisited.find(curMatrix)!=isVisited.end()) continue;

        if(hScore==9) {
            cout << gScore;
            return 0;
        }
        isVisited.insert(curMatrix);
        
        int zeroPosition = -1;
        for(int i=0; i<9; i++) {
            if(curMatrix[i]=='0') {
                zeroPosition = i;
                break;
            }
        }

        for(int i=0; i<4; i++) {
            int newPosition = zeroPosition+dy[i]+dx[i];
            if((dy[i]!=0&&newPosition>=0&&newPosition<9) || (dy[i]==0&&newPosition!=-1&&newPosition/3==zeroPosition/3)) {
                string newStr = curMatrix;
                newStr[zeroPosition] = curMatrix[newPosition];
                newStr[newPosition] = curMatrix[zeroPosition];
                if(isVisited.find(newStr)==isVisited.end()) {
                    pq.push({-(gScore+1+h(&newStr)), newStr});
                }
            }
        }
    }

    cout << "-1";
}