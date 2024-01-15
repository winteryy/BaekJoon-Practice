#include <iostream>
#include <vector>

using namespace std;

int inOrder[100001];
int inOrderInd[100001];
int postOrder[100001];

void getPreOrder(int leftInd, int rightInd, int inOrderLeft, int inOrderRight) {
    if(leftInd>rightInd) {
        return;
    }

    cout << postOrder[rightInd] << " ";
    int rootInd = inOrderInd[postOrder[rightInd]];
    int leftNum = rootInd - inOrderLeft;
    int rightNum = inOrderRight - rootInd;
    getPreOrder(leftInd, leftInd+leftNum-1, inOrderLeft, rootInd-1);
    getPreOrder(leftInd+leftNum, rightInd-1, rootInd+1, inOrderRight);
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> inOrder[i];
        inOrderInd[inOrder[i]] = i;
    }

    for(int i=1; i<=n; i++) {
        cin >> postOrder[i];
    }

    
    getPreOrder(1, n, 1, n);
}