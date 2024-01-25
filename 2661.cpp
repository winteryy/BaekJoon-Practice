#include <iostream>
#include <vector>

using namespace std;

bool flag = false;
int n;
vector<int> v;

void solve(int ind) {
    if(flag) return;

    if(ind==n) {
        for(auto num: v) {
            cout << num;
        }
        flag = true;
        return;
    }

    for(int num=1; num<=3; num++) {
        bool globalFlag = false;
        v[ind] = num;
        for(int i=ind-1; i+1>=(ind+1)/2; i--) {
            if(v[i]==num) {
                bool localFlag = true;
                for(int k=0; k<ind-i; k++) {
                    if(v[ind-k]!=v[i-k]) {
                        localFlag = false;
                        break;
                    }
                }
                if(localFlag) {
                    globalFlag = true;
                    break;
                }
            }
        }

        if(!globalFlag) {
            solve(ind+1);
        }
    }    

}


int main() {

    cin >> n;
    v = vector<int>(n);
    
    solve(0);

}