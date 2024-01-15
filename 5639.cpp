#include <iostream>
#include <stack>

using namespace std;

int preOrder[10001];

void getPostOrder(int leftInd, int rightInd) {

    if(leftInd>rightInd) {
        return;
    }

    int biggerInd = rightInd+1;
    for(int i=leftInd; i<=rightInd; i++) {
        if(preOrder[leftInd]<preOrder[i]) {
            biggerInd = i;
            break;
        }
    }

    getPostOrder(leftInd+1, biggerInd-1);
    getPostOrder(biggerInd, rightInd);
    cout << preOrder[leftInd] << "\n";

}

int main() {

    int key = 0;
    while(true){
        cin >> preOrder[key];
        if(cin.eof()) break;
        key++;
    }

    getPostOrder(0, key-1);

}