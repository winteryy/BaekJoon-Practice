#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

bool originLights[10][10];
bool newLights[10][10];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void turnSwitch(const int& r, const int& c) {
    newLights[r][c] = !newLights[r][c];

    for(int i=0; i<4; i++) {
        int nextR = r+dy[i];
        int nextC = c+dx[i];

        if(nextR>=0 && nextR<10 && nextC>=0 && nextC<10) {
            newLights[nextR][nextC] = !newLights[nextR][nextC]; 
        }
    }
}

void resetLights() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            newLights[i][j] = originLights[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> c;
            if(c=='O') {
                originLights[i][j] = true;
            } else {
                originLights[i][j] = false;
            }
        }
    }

    int result = 987654321;

    for(int i=0; i<(1<<10); i++) {
        resetLights();
        int cnt = 0;
        for(int j=0; j<10; j++) {
            if(i&(1<<j)) {
                turnSwitch(0, j);
                cnt++;
            }
        }

        for(int j=1; j<10; j++) {
            for(int k=0; k<10; k++) {
                if(newLights[j-1][k]) {
                    turnSwitch(j, k);
                    cnt++;
                }
            }
        }
        
        bool isValid = true;
        for(int j=0; j<10; j++) {
            if(newLights[9][j]) {
                isValid = false;
                break;
            }
        }

        if(isValid) result = min(result, cnt);
    }

    cout << ((result==INF) ? -1 : result);
}