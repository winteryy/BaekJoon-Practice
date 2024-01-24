#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    for(auto n: numbers) {
        answer += n;
    }
    return answer/numbers.size();
}