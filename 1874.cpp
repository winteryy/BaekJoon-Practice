#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int num, ind=1;
    vector<bool> ans; //+:true -:false
    stack<int> s;
    for(int i=0; i<n; i++) {
        cin >> num;

        if(num>=ind) {
            for(; ind<=num; ind++) {
                s.push(ind);
                ans.push_back(true);
            }
            s.pop();
            ans.push_back(false);
        }else if(s.top()==num) {
            s.pop();
            ans.push_back(false);
        }else {
            cout << "NO";
            return 0;
        }

    }

    for(auto b: ans) {
        if(b) {
            cout << "+\n";
        }else {
            cout << "-\n";
        }
    }
}