#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;

    vector<stack<int> > lines(7, stack<int>());
    
    int note, fret, cnt=0;

    for(int i=0; i<n; i++) {
        cin >> note >> fret;
        if(lines[note].empty() || fret>lines[note].top()) {
            cnt++;
            lines[note].push(fret);
        }else if(fret<lines[note].top()) {
            while(!lines[note].empty() && fret<lines[note].top()) {
                cnt++;
                lines[note].pop();
            }
            if(lines[note].empty() || lines[note].top()!=fret) {
                cnt++;
                lines[note].push(fret);
            }
        }
    }

    cout << cnt;
}