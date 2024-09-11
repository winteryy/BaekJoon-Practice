#include <iostream>
#include <algorithm>
#define INF_COST 987654321

using namespace std;

int startWithRed[1000][3]; // { red, green, blue }
int startWithGreen[1000][3];
int startWithBlue[1000][3];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n >> startWithRed[0][0] >> startWithGreen[0][1] >> startWithBlue[0][2];
    startWithRed[0][1] = INF_COST;
    startWithRed[0][2] = INF_COST;
    startWithGreen[0][0] = INF_COST;
    startWithGreen[0][2] = INF_COST;
    startWithBlue[0][0] = INF_COST;
    startWithBlue[0][1] = INF_COST;

    int redCost, greenCost, blueCost;
    for(int i=1; i<n; i++) { //마지막 원소는 따로 계산
        cin >> redCost >> greenCost >> blueCost;

        startWithRed[i][0] = min(startWithRed[i-1][1], startWithRed[i-1][2]) + redCost;
        startWithRed[i][1] = min(startWithRed[i-1][0], startWithRed[i-1][2]) + greenCost;
        startWithRed[i][2] = min(startWithRed[i-1][0], startWithRed[i-1][1]) + blueCost;

        startWithGreen[i][0] = min(startWithGreen[i-1][1], startWithGreen[i-1][2]) + redCost;
        startWithGreen[i][1] = min(startWithGreen[i-1][0], startWithGreen[i-1][2]) + greenCost;
        startWithGreen[i][2] = min(startWithGreen[i-1][0], startWithGreen[i-1][1]) + blueCost;

        startWithBlue[i][0] = min(startWithBlue[i-1][1], startWithBlue[i-1][2]) + redCost;
        startWithBlue[i][1] = min(startWithBlue[i-1][0], startWithBlue[i-1][2]) + greenCost;
        startWithBlue[i][2] = min(startWithBlue[i-1][0], startWithBlue[i-1][1]) + blueCost;                
    }   

    int candidateList[6] = {
        startWithRed[n-1][1], startWithRed[n-1][2],
        startWithGreen[n-1][0], startWithGreen[n-1][2],
        startWithBlue[n-1][0], startWithBlue[n-1][1]
    };

    int result = *min_element(candidateList, candidateList+6);

    cout << result;
}