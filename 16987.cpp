#include <iostream>
#include <vector>

using namespace std;

int n, cnt=0;
vector<pair<int, int> > eggs;

void DFS(int current) {
    if(current==n) {
        int destroyed = 0;
        for(auto p: eggs) {
            if(p.first<=0) {
                destroyed++;
            }
        }
        cnt = max(cnt, destroyed);
        return;
    }

    bool flag = false;
    for(int i=0; i<n; i++) {
        if(i!=current && eggs[current].first>0 && eggs[i].first>0) {
            flag = true;
            eggs[i].first -= eggs[current].second;
            eggs[current].first -= eggs[i].second;
            DFS(current+1);
            eggs[i].first += eggs[current].second;
            eggs[current].first += eggs[i].second;
        }
    }
    if(!flag) {
        DFS(current+1);
    }

}

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        int s, w;
        cin >> s >> w;
        eggs.push_back(make_pair(s, w));
    }

    DFS(0);

    cout << cnt;
}