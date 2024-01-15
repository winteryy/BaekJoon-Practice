#include <iostream>
#include <list>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    list<int> l;
    for(int i=1; i<=n; i++) {
        l.push_back(i);
    }

    list<int>::iterator iter = l.begin();
    for(int i=0; i<k-1; i++) {
        iter++;
        if(iter==l.end()) {
            iter = l.begin();
        }
    }
    cout << "<";
    while(l.size()>1) {
        list<int>::iterator targetIter = iter;
        iter++;
        if(iter==l.end()) {
            iter = l.begin();
        }
        cout << *targetIter << ", ";
        l.erase(targetIter);
        for(int i=0; i<k-1; i++) {
            iter++;
            if(iter==l.end()) {
                iter = l.begin();
            }
        }
    }

    cout << *iter << ">";
    
}