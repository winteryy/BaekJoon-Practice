#include <iostream>

using namespace std;

int mapMatrix[100][100];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l;
    cin >> n >> l;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mapMatrix[i][j];
        }
    }

    int validNum = 0;
    for(int i=0; i<n; i++) {
        bool validFlag = true;
        int needDownside = 0;
        int prevLevel = mapMatrix[i][0];
        int flatNum = 1;

        for(int j=1; j<n; j++) {
            if(prevLevel == mapMatrix[i][j]) {
                flatNum++;
            }

            if(prevLevel < mapMatrix[i][j]) { // upside
                if(flatNum < l*(mapMatrix[i][j]-prevLevel) || needDownside>0) {
                    validFlag = false;
                    break;
                } else {
                    flatNum = 1;
                }
            } else if(prevLevel > mapMatrix[i][j]) {
                if(needDownside>0) {
                    validFlag = false;
                    break;
                }
                needDownside = l*(prevLevel-mapMatrix[i][j]);
                flatNum = 1;
            }
            if(needDownside>0 && flatNum==needDownside) {
                needDownside = 0;
                flatNum = 0;
            }

            prevLevel = mapMatrix[i][j];
        }

        if(validFlag && needDownside == 0) validNum++;
    } 

    for(int i=0; i<n; i++) {
        bool validFlag = true;
        int needDownside = 0;
        int prevLevel = mapMatrix[0][i];
        int flatNum = 1;

        for(int j=1; j<n; j++) {
            if(prevLevel == mapMatrix[j][i]) {
                flatNum++;
                if(needDownside>0 && flatNum==needDownside) {
                    needDownside = 0;
                    flatNum = 0;
                }
            }
            
            if(prevLevel < mapMatrix[j][i]) { // upside
                if(flatNum < l*(mapMatrix[j][i]-prevLevel) || needDownside>0) {
                    validFlag = false;
                    break;
                } else {
                    flatNum = 1;
                }
            } else if(prevLevel > mapMatrix[j][i]) {
                if(needDownside>0 && flatNum<needDownside) {
                    validFlag = false;
                    break;
                }
                needDownside = l*(prevLevel-mapMatrix[j][i]);
                flatNum = 1;
            }
            if(needDownside>0 && flatNum==needDownside) {
                needDownside = 0;
                flatNum = 0;
            }

            prevLevel = mapMatrix[j][i];
        }

        if(validFlag && needDownside == 0) validNum++;
    } 

    cout << validNum;
}