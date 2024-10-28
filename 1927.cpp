#include <iostream>

using namespace std;

class MinHeap {
private:
    int* heapTree;
    int curSize, maxSize;

    void expandSize() {
        int* newTree = new int[maxSize*2+1];
        for(int i=1; i<=curSize; i++) {
            newTree[i] = heapTree[i];
        }
        maxSize *= 2;
        delete heapTree;
        heapTree = newTree;
    }

public:
    MinHeap() {
        heapTree = new int[2049];
        curSize = 0;
        maxSize = 2048;
    }

    void push(int x) {

        if(curSize+1>=maxSize) {
            expandSize();
        }

        int ind = curSize+1;
        while(ind>1) {
            if(heapTree[ind/2]>x) {
                heapTree[ind] = heapTree[ind/2];
                ind /= 2;
            } else {
                break;
            }
        }

        heapTree[ind] = x;
        curSize++;
    }

    int pop() {
        int minValue = heapTree[1];
        int x = heapTree[curSize];
        int ind = 1;
        while(ind*2<=curSize-1) {
            int originInd = ind;
            heapTree[ind] = x;

            if(heapTree[originInd*2]<x) {
                ind = originInd*2;
            }
            if(originInd*2+1<=curSize-1 && heapTree[originInd*2+1]<heapTree[ind]) {
                ind = originInd*2+1;
            }
            
            if(originInd==ind) {
                break;
            } else {
                heapTree[originInd] = heapTree[ind];
            }
        }
        heapTree[ind] = x;
        curSize--;
        return minValue;
    }

    int size() {
        return curSize;
    }

    bool isEmpty() {
        return curSize==0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cmd;
    cin >> n;

    MinHeap mh;
    while(n--) {
        cin >> cmd;
        if(cmd>0) {
            mh.push(cmd);
        } else {
            if(!mh.isEmpty()) {
                cout << mh.pop() << "\n";
            } else {
                cout << "0\n";
            }
        }
    }
}
