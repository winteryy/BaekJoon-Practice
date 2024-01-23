#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    return (n%2==0 ? (n*(1+n)/2 + n/2)/2 : (n*(1+n)/2 + n/2 - n)/2);
}