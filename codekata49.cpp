#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> ansSet;
    
    for(int i=0; i<numbers.size()-1; i++) {
        for(int j=i+1; j<numbers.size(); j++) {
            ansSet.insert(numbers[i]+numbers[j]);
        }
    }
    
    for(auto n: ansSet) {
        answer.push_back(n);
    }
    
    return answer;
}