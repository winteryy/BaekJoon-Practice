#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<int> food) {
    deque<char> dq;
    dq.push_back('0');
    
    for(int i=food.size()-1; i>=1; i--) {
        for(int j=0; j<food[i]/2; j++) {
            dq.push_back('0'+i);
            dq.push_front('0'+i);
        }
    }
    
    string answer = "";
    for(auto c: dq) {
        answer.push_back(c);
    }
    
    return answer;
}