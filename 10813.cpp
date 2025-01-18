#include <iostream>

using namespace std;

int balls[101];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        balls[i] = i;
    } 

    for(int i=0; i<m; i++) {
        int orig, dest;
        cin >> orig >> dest;

        swap(balls[orig], balls[dest]);
    }

    for(int i=1; i<=n; i++) {
        cout << balls[i] << " ";   
    }
}