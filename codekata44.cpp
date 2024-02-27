#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int longLen = 0, shortLen = 0;
    
    for(auto s: sizes) {
        if(s[0] > s[1]) {
            longLen = max(longLen, s[0]);
            shortLen = max(shortLen, s[1]);
        } else {
            longLen = max(longLen, s[1]);
            shortLen = max(shortLen, s[0]);
        }
    }
    return longLen*shortLen;
}