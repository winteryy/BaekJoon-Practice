#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a==b) return a;
    if(a<b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    return (long long)(a-b+1)*(a+b)/2;
}