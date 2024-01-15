#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    
    long long timeSum = 0;
    for(int i=0; i<food_times.size(); i++) {
        timeSum += food_times[i];
    }
    if(timeSum <= k) {
        return -1;
    }

    priority_queue<pair<int, int> > pq;

    for(int i=0; i<food_times.size(); i++) {
        pq.push({-food_times[i], i+1});
    }
    
    timeSum = 0;
    long long prevTime = 0;
    long long foodNum = food_times.size();
 
    while(timeSum + ((-pq.top().first - prevTime) * foodNum) <= k) {
        int minTime = -pq.top().first;
        pq.pop();

        timeSum += (minTime - prevTime) * foodNum;
        foodNum--;
        prevTime = minTime;

    }
    
    vector<int> remainTime;
    while(!pq.empty()) {
        remainTime.push_back(pq.top().second);
        pq.pop();
    }

    sort(remainTime.begin(), remainTime.end());

    return remainTime[(k-timeSum) % foodNum];
}