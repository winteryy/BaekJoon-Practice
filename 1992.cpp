#include <iostream>

using namespace std;

int matrix[64][64] = {0,};
int n;

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

void compress(int y, int x, int size) {

    if(isConsistent(y, x, size)) {
        cout << matrix[y][x];
    }else {
        cout << '(';
        int half = size/2;
        compress(y, x, half);
        compress(y, x+half, half);
        compress(y+half, x, half);
        compress(y+half, x+half, half);
        cout << ')';
    }
    
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    cin >> n;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++) {
            matrix[i][j] = s[j]-'0';
        }
    }

    compress(0, 0, n);
}