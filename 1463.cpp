#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<pair<int, int> > q;
    q.push({n, 0});

    vector<bool> isVisited(n+1, false);
    
    while(!q.empty()) {
        auto fr = q.front();
        q.pop();
        
        if(isVisited[fr.first]) continue;
        isVisited[fr.first] = true;

        if(fr.first==1) {
            cout << fr.second;
            break;
        }

        if(fr.first%3==0 && !isVisited[fr.first/3]) {
            q.push({fr.first/3, fr.second+1});
        }
        if(fr.first%2==0 && !isVisited[fr.first/2]) {
            q.push({fr.first/2, fr.second+1});
        }
        if(!isVisited[fr.first-1]) {
            q.push({fr.first-1, fr.second+1});
        }
    }
    
}