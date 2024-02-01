#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, ind = 0;
    bool negativeSign = false;
    if(s[ind] == '+') {
        ind++;
    }else if(s[ind] == '-') {
        negativeSign = true;
        ind++;
    }
    
    while(ind<s.size()) {
        answer *= 10;
        answer += s[ind]-'0';
        ind++;
    }
    
    return negativeSign?-answer:answer;
}