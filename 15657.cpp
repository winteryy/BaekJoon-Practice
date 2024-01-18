#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> ans;

void choice(int current, int depth, int recent) {
    if(current==depth) {
        for(auto n: ans) {
            cout << n << " ";
        }
        cout << "\n";
        return;
    }else {
        for(int i=recent; i<arr.size(); i++) {
            ans.push_back(arr[i]);
            choice(current+1, depth, i);
            ans.pop_back();
            
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    choice(0, m, 0);
}