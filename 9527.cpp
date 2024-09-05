#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> oneList; //ind : 2^ind 일 때 참조해야 하는 인덱스

void fillOneList(ll num) {
    ll ex = 1;
    ll curSum = 0;

    while(ex<=num) {
        oneList.push_back(curSum);
        curSum = (curSum << 1) + ex;
        ex = ex << 1;
    }
}

ll getOneNum(ll num) {
    ll totalOneNum = 0;
    ll appearanceOne = 0;

    int bitInd = 0;
    ll twoMutiple = 1;

    while(twoMutiple <= num) {
        bitInd++;
        twoMutiple = twoMutiple<<1;
    }

    ll bitCursor = 1LL << bitInd-1;
    bitInd--;

    while(bitCursor>0) {
        if(num & bitCursor) {
            totalOneNum += oneList[bitInd];
            totalOneNum += appearanceOne * 1<<bitInd;
            appearanceOne++;
        }
        bitCursor = bitCursor >> 1;
        bitInd--; 
    }
    totalOneNum += appearanceOne;

    return totalOneNum;
}

ll getOneNumInRange(ll start, ll end) {
    fillOneList(end);

    return getOneNum(end)-getOneNum(start-1);
}

int main() {
    
    ll a, b;

    cin >> a >> b;

    cout << getOneNumInRange(a, b);
}