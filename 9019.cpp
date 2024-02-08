#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int D(int n) {
    return n*2%10000;
}

int S(int n) {
    return (n-1==-1?9999:n-1);
}

int L(int n) {
    int newN = n%1000;
    newN *= 10;
    newN += n/1000;

    return newN;
}

int R(int n) {
    int newN = n/10;
    newN += n%10*1000;

    return newN;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int t; 
    cin >> t;

    int a, b;

    for(int i=0; i<t; i++) {
        cin >> a >> b;

        register vector<pair<int, char> > isVisited(10000, {-1, 'A'});
        register queue<pair<int, pair<int, char> > > q;

        q.push({a, {-1, 'A'}});

        while(!q.empty()) {
            int value = q.front().first;
            pair<int, char> curCmd = q.front().second;

            q.pop();

            if(isVisited[value].first!=-1) continue;
            isVisited[value] = curCmd;
            if(value==b) {
                deque<char> dq;
                int num=value;
                while(num!=a) {
                    dq.push_front(isVisited[num].second);
                    num = isVisited[num].first;
                }
                for(auto c: dq) {
                    cout << c;
                }
                break;
            }



            if(isVisited[D(value)].first==-1) {
                q.push({D(value), {value, 'D'}});   
            }

            if(isVisited[S(value)].first==-1) {
                q.push({S(value),  {value, 'S'}});                
            }

            if(isVisited[L(value)].first==-1) {
                q.push({L(value),  {value, 'L'}});        
            }

            if(isVisited[R(value)].first==-1) {
                q.push({R(value),  {value, 'R'}});              
            }
      
        }
        cout << "\n";
    }

    return 0;
}