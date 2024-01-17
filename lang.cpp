#include <iostream>
#include <random>
#include <vector>

using namespace std;

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 98); // total 99

bool isSSR() {
    int randNum = dist(mt);
    
    return randNum == 0;
}

int gachaForSSR() {
    int cnt = 1;
    for(; cnt<100; cnt++) {
        if(isSSR()) {
            break;
        }
    }
    return cnt;
}

int gachaForTicket() {
    int tickets = 100;
    int cnt = 0;

    while(tickets>0) {
        int usedTicket = gachaForSSR();
        if(usedTicket<=tickets) {
            tickets -= usedTicket;
            cnt++;
        }else {
            break;
        }
    }

    return cnt;
}

int main() {

    vector<int> result(101, 0);
    vector<int> accSum(101, 0);
    vector<double> per(101, 0);
    vector<double> accDist(101, 0);
    double totalP = 0;

    // for(int i=0; i<1000000; i++) {
    //     int num = gachaForSSR();
    //     result[num]++;
    // }

    // for(int i=1; i<=100; i++) {
    //     per[i] = (double)result[i]/1000000;
    //     accSum[i] = accSum[i-1] + result[i];
    // }
    
    // for(int i=1; i<=100; i++) {
    //     totalP += per[i]*i;
    // }

    // totalP = 1/totalP;
    double sum = 0;
    for(int i=0; i<100000; i++) {
        int heros = gachaForTicket();
        result[heros]++;
        sum += (double)heros;
    } 
    sum /= 100000;

    return 0;
}