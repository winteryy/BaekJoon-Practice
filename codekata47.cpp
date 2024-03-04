#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int charInd;

bool cmp(string l, string r) {
    if(l[charInd] == r[charInd]) {
        return l<=r;
    }else{
        return l[charInd] < r[charInd];
    }
}

vector<string> solution(vector<string> strings, int n) {
    charInd = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}