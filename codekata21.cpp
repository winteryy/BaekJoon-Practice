#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0, origin = x;
    while(x>0) {
        sum += x%10;
        x /= 10;
    }
        
    return origin%sum==0;
}