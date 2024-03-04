#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> alphaArr(26, -1);
    
    for(int i=0; i<s.size(); i++) {
        int alpha = s[i]-'a';
        
        if(alphaArr[alpha]==-1) {
            answer.push_back(-1);
        }else {
            answer.push_back(i-alphaArr[alpha]);
        }
        
        alphaArr[alpha] = i;
    }
    return answer;
}