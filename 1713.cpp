#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int frame, n;
    cin >> frame >> n;

    int currentFrame = 0;
    int orderNum = 1;
    int stdNum;
    vector<pair<int, int> > students(101, make_pair(0, 0));
    
    for(int i=0; i<n; i++) {
        cin >> stdNum;
        
        if(students[stdNum].first!=0) {
            students[stdNum].first++;
        }else if(currentFrame<frame) {
            students[stdNum].first=1;
            students[stdNum].second=orderNum;
            orderNum++;
            currentFrame++;
        }else {
            int minOrd=5000, minCount=5000;
            int targetStdNum;
            for(int j=1; j<=100; j++) {
                if(students[j].first!=0) {
                    if(minCount>students[j].first) {
                        minCount = students[j].first;
                        minOrd = students[j].second;
                        targetStdNum = j;
                    }else if(minCount==students[j].first && minOrd>students[j].second) {
                        minOrd = students[j].second;
                        targetStdNum = j;
                    }
                }
            }

            students[targetStdNum].first=0;
            students[stdNum].first=1;
            students[stdNum].second=orderNum;
            orderNum++;
        }

    }

    for(int i=1; i<=100; i++) {
        if(students[i].first!=0) {
            cout << i << " ";
        }
    }
}