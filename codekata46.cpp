#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    vector<pair<string, string> > exVec;
    exVec.push_back({"zero", "0"});
    exVec.push_back({"one", "1"});
    exVec.push_back({"two", "2"}); 
    exVec.push_back({"three", "3"}); 
    exVec.push_back({"four", "4"}); 
    exVec.push_back({"five", "5"}); 
    exVec.push_back({"six", "6"}); 
    exVec.push_back({"seven", "7"}); 
    exVec.push_back({"eight", "8"}); 
    exVec.push_back({"nine", "9"}); 
    
    for(auto e: exVec) {
        size_t nPos = s.find(e.first);
        
        while(nPos != string::npos) {
            s.replace(nPos, e.first.size(), e.second);
            nPos = s.find(e.first);
        }
    }

    for(auto c: s) {
        answer*=10;
        answer+=c-'0';
    }
    return answer;
}
