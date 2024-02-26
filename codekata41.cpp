#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    bool check = true;
    string answer = "";
    
    for(auto c: s) {
        if(c==' ') {
            check = true;
            answer.push_back(' ');
        }else {
            if(check&&islower(c)) {
                answer.push_back(c-32);
            }else if(!check&&isupper(c)) {
                answer.push_back(c+32);
            }else {
                answer.push_back(c);
            }
            check = !check;
        }
    }
    return answer;
}