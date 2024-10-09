#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numVector;
    vector<long long> result(10, 0);
    int num = n;
    while(num>0) {
        numVector.push_back(num%10);
        num/=10;
    }

    for(int i=0; i<numVector.size(); i++) {
        long long prev = 10;
        for(int j=0; j<i; j++) prev *= 10;
        long long subs = prev/10;
        prev = n/prev;

        if(prev>0) {
            long long baseSum = prev * subs;
            // 0~prev-1   [0~9]   0~아래 최대
            for(int j=0; j<10; j++) {
                result[j] += baseSum;
            }
            //앞자리 0으로 채워지고, 지금 자리도 0인 경우 
            result[0] -= subs;
        }


        //prev  [0~자리에 위치한 수 -1]  0~아래 최대
        for(int j=0; j<numVector[i]; j++) {
            result[j] += subs;
        }
        if(i==numVector.size()-1) {
            //탐색 중인 자리가 제일 앞자리일 때 0 갯수 카운트 x
            result[0] -= subs;
        }

        // prev [자리 위치 수] 0~아래 최대
        result[numVector[i]] += n%subs+1;
    }

    for(int res: result) {
        cout << res << " ";
    }

}