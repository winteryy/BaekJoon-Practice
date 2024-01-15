#include <iostream>
#include <vector>
#include <random>

using namespace std;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(0, 999);

bool getRandResult(int p) {
    int randNum = dist(mt);
    return randNum < p;
}

int getSSR() {
    int cnt = 0;
    int halfCnt = 0;
    bool getTarget = false;
    bool halfCeil = false;

    while(!getTarget) {
        cnt++;

        if(cnt<=60) { //확업 이전
            if(getRandResult(15)){
                if(halfCeil) {
                    getTarget = true;
                }else if(getRandResult(500)) {
                    getTarget = true;
                }else {
                    halfCeil = true;
                    halfCnt = cnt;
                    cnt = 0;
                }
            }
        }else if(cnt==70) { //(반)천장
            if(halfCeil) {
                getTarget = true;
            }else if(getRandResult(500)) {
                getTarget = true;
            }else {
                halfCeil = true;
                halfCnt = cnt;
                cnt = 0;                
            }
        }else { //확업
            if(getRandResult(15+(cnt-60)*25)) {
                if(halfCeil) {
                    getTarget = true;
                }else if(getRandResult(500)) {
                    getTarget = true;
                }else {
                    halfCeil = true;
                    halfCnt = cnt;
                    cnt = 0;
                }
            }
        }
    }

    return (halfCeil ? cnt+halfCnt : cnt);
}

int main() {

    vector<int> stat(141, 0);
    vector<double> pd(141, 0);
    vector<double> cdf(141, 0);
    double arithMean = 0.0; 
    for(int i=0; i<5000000; i++) {
        int num = getSSR();
        stat[num]++;
    }

    for(int i=1; i<141; i++) {
        pd[i] = (double)stat[i]/5000000;
    }

    for(int i=1; i<141; i++) {
        cdf[i] = pd[i] + cdf[i-1];
    }

    for(int i=1; i<141; i++) {
        arithMean += (double)stat[i]*i;
    }

    arithMean/=(double)5000000;

}