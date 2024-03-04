#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto cmd: commands) {
        vector<int> newArr;
        
        for(int i=cmd[0]-1; i<cmd[1]; i++) {
            newArr.push_back(array[i]);
        }
        
        sort(newArr.begin(), newArr.end());
        
        answer.push_back(newArr[cmd[2]-1]);
    }

    return answer;
}