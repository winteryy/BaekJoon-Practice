#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    queue<int> router;
    
    int n, packet;
    cin >> n >> packet;

    while(packet!=-1) {
        if(packet==0) {
            router.pop();
        }else {
            if(router.size()<n) {
                router.push(packet);
            } 
        }
        cin >> packet;
    }

    if(router.size()==0) {
        cout << "empty";
    }else {
        while(!router.empty()) {
            cout << router.front() << " ";
            router.pop();
        }
    }
}