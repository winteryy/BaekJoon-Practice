#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<bool> isVisited; 
vector<int> ans;

void choice(int current, int depth) {
    if(current==depth) {
        for(auto n: ans) {
            cout << n << " ";
        }
        cout << "\n";
        return;
    }else {
        for(int i=0; i<arr.size(); i++) {
            if(!isVisited[i]) {
                isVisited[i] = true;
                ans.push_back(arr[i]);
                choice(current+1, depth);
                isVisited[i] = false;
                ans.pop_back();
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    isVisited = vector<bool>(n, false);

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    choice(0, m);
}