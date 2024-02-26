#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string s;
    while(n>0) {
        s.push_back(n%3 + '0');
        n/=3;
    }
    
    int mult = 1;
    int answer = 0;

    for(int i=s.size()-1; i>=0; i--) {
        answer += (s[i]-'0')*mult;
        mult *= 3;
    }
    
    return answer;
}