#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i=left; i<=right; i++) {
        double rt = sqrt(i);
        if(abs(rt-(int)rt) < 1e-12) {
            answer -= i;
        }else {
            answer += i;
        }
    }
    return answer;
}