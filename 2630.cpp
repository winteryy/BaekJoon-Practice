#include <iostream>

using namespace std;

int n;
bool matrix[128][128];

pair<int, int> getColorNum(int y, int x, int size) { // return : {white, blue}
    if(size == 1) {
        if(matrix[y][x]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }

    int whiteNum = 0;
    int blueNum = 0;
    int halfSize = size/2;
    pair<int, int> parts[4] = {{y, x}, {y, x+halfSize}, {y+halfSize, x}, {y+halfSize, x+halfSize}};
    
    for(auto part : parts) {
        pair<int, int> partResult = getColorNum(part.first, part.second, halfSize);
        whiteNum += partResult.first;
        blueNum += partResult.second;
    }

    if(whiteNum==0) {
        return {0, 1};
    } else if(blueNum==0) {
        return {1, 0};
    } else {
        return {whiteNum, blueNum};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    auto result = getColorNum(0, 0, n);
    cout << result.first << "\n" << result.second;
}