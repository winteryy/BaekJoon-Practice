#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool flag = false;
int n, d;
vector<int> isExist;
vector<int> answer;

void solution(int depth) {
    if(flag) return;

    if(depth==-1) {
        for(int i=0; i<d; i++) {
            if(isExist[i]!=1) {
                return;
            }
        }

        long long result = 0;
        for(int i=0; i<d; i++) {
            result += answer[i]*pow(d, i);
        }
        if(result>n) {
            cout << result;
            flag = true;
        }
        return;
    }else {
        for(int i=0; i<d; i++) {
            if(isExist[i]>1) {
                return;
            }
        }
    }

    if(depth == d-1) {
        for(int i=1; i<d; i++) {
            answer[depth] = i;
            isExist[i]++;
            solution(depth-1);
            isExist[i]--;
        }
    }else {
        for(int i=0; i<d; i++) {
            answer[depth] = i;
            isExist[i]++;
            solution(depth-1);
            isExist[i]--;
        }
    }

}

int main() {

    cin >> n >> d;

    isExist = vector<int>(d, 0);
    answer = vector<int>(d, 0);

    solution(d-1);
    if(!flag) {
        cout << "-1";
    }

}