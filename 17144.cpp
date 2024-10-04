#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    int r, c, t;
    cin >> r >> c >> t;

    vector<vector<int> >* matrix = new vector<vector<int> >(r, vector<int>(c, 0));
    pair<int, int> cleanerPosition; // {r, c}

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> (*matrix)[i][j];
            if((*matrix)[i][j]==-1) {
                cleanerPosition = {i, j};
            }
        }
    }

    vector<vector<int> >* newMatrix;
    for(int time=0; time<t; time++) {
        //미세먼지 확산
        newMatrix = new vector<vector<int> >(r, vector<int>(c, 0));
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                int cnt = 0;
                if((*matrix)[i][j]>0) {
                    for(int k=0; k<4; k++) {
                        int adjR = i+dy[k];
                        int adjC = j+dx[k];
                        if(adjR>=0 && adjR<r && adjC>=0 && adjC<c && (*matrix)[adjR][adjC]!=-1) {
                            (*newMatrix)[adjR][adjC] += (*matrix)[i][j] / 5;
                            cnt++;
                        }
                    }
                    (*newMatrix)[i][j] += (*matrix)[i][j] - ((*matrix)[i][j]/5*cnt);
                } else {
                    (*newMatrix)[i][j] += (*matrix)[i][j];
                }
            }
        }

        //공기 청정기
        //위쪽
        int posY = cleanerPosition.first-2;
        int posX = cleanerPosition.second;

        while(posY>0) { 
            (*newMatrix)[posY][posX] = (*newMatrix)[posY-1][posX];
            posY--;
        }
        while(posX<c-1) {
            (*newMatrix)[posY][posX] = (*newMatrix)[posY][posX+1];
            posX++;
        }
        while(posY<cleanerPosition.first-1) {
            (*newMatrix)[posY][posX] = (*newMatrix)[posY+1][posX];
            posY++;
        }
        while(posX>1) {
            (*newMatrix)[posY][posX] = (*newMatrix)[posY][posX-1];
            posX--;
        }
        (*newMatrix)[posY][posX] = 0;

        //아래쪽        
        posY = cleanerPosition.first+1;
        posX = cleanerPosition.second;
        while(posY<r-1) {
            (*newMatrix)[posY][posX] = (*newMatrix)[posY+1][posX];
            posY++;
        }
        while(posX<c-1) {
            (*newMatrix)[posY][posX] = (*newMatrix)[posY][posX+1];
            posX++;
        }        
        while(posY>cleanerPosition.first) {
            (*newMatrix)[posY][posX] = (*newMatrix)[posY-1][posX];
            posY--;
        }
        while(posX>1) {
            (*newMatrix)[posY][posX] = (*newMatrix)[posY][posX-1];
            posX--;
        }
        (*newMatrix)[posY][posX] = 0;

        delete matrix;
        matrix = newMatrix;
    }

    int sum = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if((*matrix)[i][j]>0) {
                sum += (*matrix)[i][j];
            }
        }
    } 
    cout << sum;   
}