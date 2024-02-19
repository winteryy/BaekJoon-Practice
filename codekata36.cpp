#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size()==4 || s.size()==6) {
        for(auto c: s) {
            if(!isdigit(c)) {
                return false;
            }
        }
    }else {
        return false;
    }
    
    return answer;
}