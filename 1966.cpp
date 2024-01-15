#include <iostream>
#include <queue>

using namespace std;

int main() {

    int t;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int n, m;
        cin >> n >> m;
        queue<pair<int, int> > q;
        
        int num;
        for(int j=0; j<n; j++) {
            cin >> num;
            q.push(make_pair(j, num));
        }

        int order = 1;
        while(!q.empty()) {
            int maxPriority=0, locInd=0;

            for(int j=0; j<q.size(); j++) {
                if(q.front().second>maxPriority) {
                    maxPriority = q.front().second;
                    locInd = j;
                }
                q.push(q.front());
                q.pop();
            }

            for(int j=0; j<locInd; j++) {
                q.push(q.front());
                q.pop();
            }

            if(q.front().first == m) {
                cout << order << "\n";
                break;
            }else {
                q.pop();
                order++;
            }
        }
    }

}
