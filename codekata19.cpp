#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    
    long long rt = sqrt(n);
    if(rt*rt==n) return (rt+1)*(rt+1); 
    return -1;
}