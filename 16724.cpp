#include <iostream>
#include <unordered_map>

using namespace std;

int root[1000000];
char matrix[1000][1000];
bool isVisited[1000][1000];

int find(int x) {
    if(root[x] == x) {
        return x;
    } else {
        root[x] = find(root[x]);
        return root[x];
    }
}

void makeUnion(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if(rootX<rootY) {
        root[y] = rootX;
    } else {
        root[x] = rootY;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
            root[i*1000 + j] = i*1000 + j;
        }
    }

    int curY, curX, curInd;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            curY = i;
            curX = j;
            curInd = i*1000 + j;

            while(!isVisited[curY][curX]) {
                isVisited[curY][curX] = true;

                switch(matrix[curY][curX]) {
                    case 'R': {
                        curX++;
                        break;
                    }
                    case 'D': {
                        curY++;
                        break;
                    }
                    case 'L': {
                        curX--;
                        break;
                    }
                    case 'U': {
                        curY--;
                    }
                }

                makeUnion(curInd, curY * 1000 + curX);   
            }
        }
    }

    unordered_map<int, int> um;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            um[find(i*1000+j)]++;
        }
    }

    cout << um.size();
}