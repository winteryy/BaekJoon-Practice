#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int answer = 0;
    for(auto n: arr) {
        answer+=n;
    }
    return (double)answer/arr.size();
}