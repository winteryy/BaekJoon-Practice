#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long pNum = 0;
    for(int i=0; i<p.size(); i++) {
        pNum *= 10;
        pNum += p[i]-'0';
    }
    for(int i=0; i<=t.size()-p.size(); i++) {
        long long tNum = 0;
        for(int j=0; j<p.size(); j++) {
            tNum *= 10;
            tNum += t[i+j]-'0';
        }
        
        if(tNum<=pNum) answer++;
    }
    return answer;
}