#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(long long n) {
    priority_queue<int> pq;
    
    while(n>0) {
        pq.push(n%10);
        n/=10;
    }
    
    long long answer = 0;
    
    while(!pq.empty()) {
        answer *= 10;
        answer += pq.top();
        pq.pop();
    }
    return answer;
}