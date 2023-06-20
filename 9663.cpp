#include <iostream>
#include <cmath>

using namespace std;

int n, count=0;
int col[15] = {0,};

bool isPromising(int ind){
    for(int i=0; i<ind; i++){
        if(col[i]==col[ind] || abs(col[i]-col[ind])==ind-i){
            return false;
        }
    }
    return true;
}

void queen(int ind){
    if(isPromising(ind)){
        if(ind==n-1){
            count++;
        }else if(ind<n){
            for(int i=0; i<n; i++){
                col[ind+1] = i;
                queen(ind+1);
            }
        }
    }
}

int main(){

    cin >> n;
    queen(-1);

    cout << count;
}