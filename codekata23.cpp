#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long collatz = num;
    
    while(collatz != 1) {
        if(collatz % 2 == 0) {
            collatz /= 2;
        }else {
            collatz = collatz * 3 + 1;
        }
        answer++;
        if(answer == 500) {
            answer = -1;
            break;
        }
    }

    return answer;
}