#include <iostream>

using namespace std;

int matrix[2187][2187];
int papers[3] = {0, 0, 0};

bool isConsistent(int y, int x, int size) {
    int first = matrix[y][x];
    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            if(matrix[i][j]!=first) {
                return false;
            }
        }
    }

    return true;
}

void cutPaper(int y, int x, int size) {
    if(isConsistent(y, x, size)) {
        if(matrix[y][x]==-1) {
            papers[2]++;
        }else {
            papers[matrix[y][x]]++;
        }
    }else {
        int div = size/3;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cutPaper(y+div*i, x+div*j, div);
            }
        } 
        
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    cutPaper(0, 0, n);

    cout << papers[2] << '\n' << papers[0] << '\n' << papers[1];
    return 0;
}