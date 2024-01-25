#include <iostream>

using namespace std;

int paper[10][10] = {0,};
int colorPaper[6] = {0, 5, 5, 5, 5, 5};
int nextY=0, nextX=0;
int minColorPaper = 26;

void fill(int y, int x, int size, int num) {
    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            paper[i][j] = num;
        }
    }
}

bool canFill(int y, int x, int size) {
    if(y+size>10 || x+size>10) {
        return false;
    }
    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            if(paper[i][j]==0) {
                return false;
            }
        }
    }

    return true;
}

void findNext(int y, int x) {
    for(int i=y; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(paper[i][j]==1) {
                nextY = i;
                nextX = j;
                return;
            }
        }
    }

    nextY = -1;
    nextX = -1;
    return;
}

void DFS(int y, int x, int cnt) {
    if(minColorPaper<=cnt) {
        return;
    }
    findNext(y, x);
    if(nextX==-1&&nextY==-1) {
        minColorPaper = cnt;
        return;
    }

    int nY = nextY;
    int nX = nextX;

    for(int k=5; k>=1; k--) {
        if(colorPaper[k] == 0) continue;
        if(!canFill(nY, nX, k)) continue;

        colorPaper[k]--;
        fill(nY, nX, k, 0);
        DFS(nY, nX, cnt+1);
        fill(nY, nX, k, 1);
        colorPaper[k]++;
    }
}

int main() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> paper[i][j];
        }
    }

    DFS(0, 0, 0);

    if(minColorPaper==26) {
        cout << "-1";
        return 0;
    }

    cout << minColorPaper;
    return 0;
}