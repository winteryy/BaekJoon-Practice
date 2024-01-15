#include <iostream>
#include <list>

using namespace std;

class Number {
public: 
    int nums[3];

    Number(int n) {
        nums[0] = n/100;
        nums[1] = n%100/10;
        nums[2] = n%10;  
    }

    bool isValid() {
        return !(nums[0]==nums[1] || nums[0]==nums[2] || nums[1]==nums[2]) && (nums[0]!=0 && nums[1]!=0 && nums[2]!=0);
    }
};

int main() {
    int n;
    cin >> n;

    list<Number> ans;
    for(int i=123; i<=987; i++) {
        Number temp = Number(i);
        if(temp.isValid()) {
            ans.push_back(temp);
        }
    }

    int num, s, b;

    for(int i=0; i<n; i++) {
        cin >> num >> s >> b;
        Number curNum = Number(num);

        list<Number>::iterator iter = ans.begin();
        for(; iter!=ans.end();) {
            int curS = 0, curB = 0;

            for(int j=0; j<3; j++) {
                if(iter->nums[j]==curNum.nums[j]) {
                    curS++;
                }else if(iter->nums[j]==curNum.nums[(j+1)%3] || iter->nums[j]==curNum.nums[(j+2)%3]) {
                    curB++;
                }
            }

            if(curS!=s || curB!=b) {
                iter=ans.erase(iter);
            }else {
                iter++;
            }
        }
    }

    cout << ans.size();
}