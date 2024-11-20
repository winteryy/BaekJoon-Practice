#include <iostream>

using namespace std;

typedef long long ll;

double deltaT = 0.001;

ll bigPow(ll base, ll exp) {
    if(exp==1) {
        return base;
    }

    ll half = bigPow(base, exp/2);
    if(exp%2==0) {
        return half*half;
    } else {
        return half*half*base;
    }
}

class Box {
public:
    double v, pos;
    ll m;

    Box(double v, ll m, double p) {
        this->v = v;
        this->m = m;
        this->pos = p;
    }

    void updatePos() {
        pos += v*deltaT;
    }
};

int main() {
    int userInput;
    cout << "set b2 mass: ";
    cin >> userInput;

    Box b1(0, 1, 200);
    Box b2(-500, bigPow(100, userInput), 300);

    ll collisionCnt = 0;
    while(b1.v<0||b2.v<0||b1.v>b2.v) {
        b1.updatePos();
        b2.updatePos();

        if(b1.pos <= 0) {
            b1.pos = 0;
            b1.v *= -1;
            collisionCnt++;
        }

        if(b1.pos >= b2.pos) {
            b1.pos = b2.pos;
            double I = b1.m * b1.v + b2.m * b2.v;
            
            ll m1 = b1.m;
            ll m2 = b2.m;
            double v1 = b1.v;
            double v2 = b2.v;

            b1.v = ((m1-m2)*v1 + 2*m2*v2)/(m1+m2);
            b2.v = ((m2-m1)*v2 + 2*m1*v1)/(m1+m2);

            collisionCnt++;
        }
    }

    cout << "count num is: " << collisionCnt;
}