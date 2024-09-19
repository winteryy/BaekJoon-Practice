#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

class Shark {
public: 
    int r, c, s, d, z;

    Shark(int r, int c, int s, int d, int z) {
        this->r = r;
        this->c = c;
        this->s = s;
        this->d = d;
        this->z = z;
    }

    bool operator < (const Shark& obj) const {
        if(this->r == obj.r) return this->z < obj.z;
        return this->r > obj.r;        
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int r, c, m;
    int sharkR, sharkC, s, d, z;
    cin >> r >> c >> m;

    vector<priority_queue<Shark> > pqByRowList(c+1);

    for(int i=0; i<m; i++) {
        cin >> sharkR >> sharkC >> s >> d >> z;
        pqByRowList[sharkC].push(
            Shark(
                sharkR, sharkC, s, d, z
            )
        );
    }

    int result = 0;
    int rCycle = r*2-2;
    int cCycle = c*2-2;
    for(int i=1; i<=c; i++) {
        bool acquireFlag = false;
        
        vector<priority_queue<Shark> > newPqRowList(c+1); //이동 후 상어 리스트

        for(int j=1; j<=c; j++) { //상어 처리
            while(!pqByRowList[j].empty()) { //열에 상어 있는 경우
                auto target = pqByRowList[j].top(); 
                pqByRowList[j].pop();
                while(!pqByRowList[j].empty() && pqByRowList[j].top().r == target.r) { //같은 행 잔여 상어 있으면 잡아먹는 처리
                    pqByRowList[j].pop();
                }
                if(!acquireFlag && i==j) {
                    result+=target.z;
                    acquireFlag = true;
                    continue;
                }
                
                switch(target.d) {
                    case 1: {
                        int order = (target.s + r - target.r) % rCycle;
                        if(order>rCycle/2) {
                            newPqRowList[target.c].push(Shark(
                                order-rCycle/2+1, target.c, target.s, 2, target.z
                            )); 
                        } else {
                            newPqRowList[target.c].push(Shark(
                                r-order, target.c, target.s, 1, target.z
                            )); 
                        } 
                        break;
                    }
                    case 2: {
                        int order = (target.s + target.r - 1) % rCycle;
                        if(order>rCycle/2) {
                            newPqRowList[target.c].push(Shark(
                                r-(order-rCycle/2), target.c, target.s, 1, target.z
                            )); 
                        } else {
                            newPqRowList[target.c].push(Shark(
                                order+1, target.c, target.s, 2, target.z
                            )); 
                        } 
                        break;
                    }
                    case 3: {
                        int order = (target.s + target.c - 1) % cCycle;
                        if(order>cCycle/2) {
                            newPqRowList[c-(order-cCycle/2)].push(Shark(
                                target.r, c-(order-cCycle/2), target.s, 4, target.z
                            )); 
                        } else {
                            newPqRowList[order+1].push(Shark(
                                target.r, order+1, target.s, 3, target.z
                            )); 
                        } 
                        break;
                    }
                    case 4: {
                        int order = (target.s + c - target.c) % cCycle;
                        if(order>cCycle/2) {
                            newPqRowList[order-cCycle/2+1].push(Shark(
                                target.r, order-cCycle/2+1, target.s, 3, target.z
                            )); 
                        } else {
                            newPqRowList[c-order].push(Shark(
                                target.r, c-order, target.s, 4, target.z
                            )); 
                        } 
                        break;
                    }
                }
            }
                        
        }
        
        pqByRowList = newPqRowList;
    }

    cout << result;
}