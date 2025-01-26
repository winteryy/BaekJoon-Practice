#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getCWRotatedPoint(pair<int, int> origin, pair<int, int> point) {
    int lengthY = point.first-origin.first;
    int lengthX = point.second-origin.second;

    return {origin.first+lengthX, origin.second-lengthY};
}

int main() {
    int n, x, y, d, g;
    vector<vector<bool> > matrix(101, vector<bool>(101, false));

    cin >> n;
    while(n--) {
        cin >> x >> y >> d >> g;

        vector<pair<int, int> > dragon;
        dragon.push_back({y, x});        
        if(d==0) {
            dragon.push_back({y, x+1});
        } else if(d==1) {
            dragon.push_back({y-1, x});
        } else if(d==2) {
            dragon.push_back({y, x-1});
        } else {
            dragon.push_back({y+1, x});
        }

        while(g--) {
            int curSize = dragon.size();
            pair<int, int> lastPoint = dragon[curSize-1];
            for(int i=curSize-2; i>=0; i--) {
                dragon.push_back(getCWRotatedPoint(lastPoint, dragon[i]));
            }
        }

        for(auto p: dragon) {
            matrix[p.first][p.second] = true;
        }
    }

    int cnt = 0;

    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(matrix[i][j] && matrix[i][j+1] && matrix[i+1][j] && matrix[i+1][j+1]) cnt++;
        }
    }

    cout << cnt;
}