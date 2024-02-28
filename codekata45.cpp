#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(auto c: s) {
        if(c==' ') {
            answer.push_back(' ');
        }else {
            answer.push_back((isupper(c) ? (c-'A'+n)%26+'A' : (c-'a'+n)%26+'a'));
        }

    }
    return answer;
}