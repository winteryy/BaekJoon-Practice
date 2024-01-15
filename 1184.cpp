#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int length;

int matrix[52][52] = {0};
int accMatrix[52][52] = {0};

vector<int> areaVector1;
vector<int> areaVector2;

void calcTopStart(int x, int y) {

    for(int i=y-1; i>=1; i--) {
        int rowSum = 0;

        for(int j=x-1; j>=1; j--) {
            
            rowSum += matrix[i][j];

            accMatrix[i][j] = rowSum;

            if(i!=y-1) {
                accMatrix[i][j] += accMatrix[i+1][j];
            }

            areaVector1.push_back(accMatrix[i][j]);

        }
    }

}

void calcTopEnd(int x, int y) {

    for(int i=y-1; i>=1; i--) {
        int rowSum = 0;

        for(int j=x; j<=length; j++) {
            
            rowSum += matrix[i][j];

            accMatrix[i][j] = rowSum;

            if(i!=y-1) {
                accMatrix[i][j] += accMatrix[i+1][j];
            }

            areaVector1.push_back(accMatrix[i][j]);

        }
    }

}

void calcBottomStart(int x, int y) {

    for(int i=y; i<=length; i++) {
        int rowSum = 0;

        for(int j=x-1; j>=1; j--) {
            
            rowSum += matrix[i][j];

            accMatrix[i][j] = rowSum;

            if(i!=y) {
                accMatrix[i][j] += accMatrix[i-1][j];
            }

            areaVector2.push_back(accMatrix[i][j]);
        }
    }

}

void calcBottomEnd(int x, int y) {

    for(int i=y; i<=length; i++) {
        int rowSum = 0;

        for(int j=x; j<=length; j++) {
            
            rowSum += matrix[i][j];

            accMatrix[i][j] = rowSum;

            if(i!=y) {
                accMatrix[i][j] += accMatrix[i-1][j];
            }

            areaVector2.push_back(accMatrix[i][j]);
        }
    }

}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> length;
    
    for(int i=1; i<=length; i++) {
        for(int j=1; j<=length; j++) {
            cin >> matrix[i][j];
        }
    }

    int cnt = 0;

    for(int i=2; i<=length; i++) {
        for(int j=2; j<=length; j++) {
            calcTopStart(j, i);
            calcBottomEnd(j, i);

            for(auto v1: areaVector1) {
                for(auto v2: areaVector2) {
                    if(v1==v2) {
                        cnt++;
                    }
                }
            }

            areaVector1.clear();
            areaVector2.clear();

            calcTopEnd(j, i);
            calcBottomStart(j, i);

            for(auto v1: areaVector1) {
                for(auto v2: areaVector2) {
                    if(v1==v2) {
                        cnt++;
                    }
                }
            }

            areaVector1.clear();
            areaVector2.clear();
        }
    }
 
    cout << cnt;
}