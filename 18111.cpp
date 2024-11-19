#include <iostream>

using namespace std;

int blocks[500][500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, b;
    cin >> n >> m >> b;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> blocks[i][j];
        }
    }

    pair<int, int> optimal = {INT32_MAX, 0};
    for(int h=256; h>=0; h--) {
        int over = 0;
        int lack = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int diff = blocks[i][j] - h;
                if(diff<0) {
                    lack -= diff;
                } else {
                    over += diff;
                }
            }
        }
        if(over+b>=lack && over*2+lack<optimal.first) {
            optimal = {over*2+lack, h};
        } 
    }

    cout << optimal.first << " " << optimal.second;  
}