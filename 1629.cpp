#include <iostream>

using namespace std;
typedef long long ll;
ll A, B, C;

ll getPow(ll base, ll exp){
    if(exp==1){
        return base%C;
    }else{
        ll temp = getPow(base, exp/2);
        temp = temp * temp % C;

        if(exp%2){
            temp = temp * base % C;
        }
        return temp;
    }
}

int main(){
    cin >> A >> B >> C;

    cout << getPow(A, B);
}