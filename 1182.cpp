#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<bool> isVisited;
int s;

int getSubArrNum(int now, int current, int depth) {
    if(current==depth) {
        int sum = 0;
        for(int i=1; i<isVisited.size(); i++) {
            if(isVisited[i]) {
                sum += arr[i];
            }
        }
        if(sum == s) {
            return 1;
        }else {
            return 0;
        }
    }else {
        int sum = 0;
        if(depth-current > arr.size()-now-1) {
            return 0;
        }
        for(int i=now+1; i<arr.size(); i++) {
            isVisited[i] = true;
            sum += getSubArrNum(i, current+1, depth);
            isVisited[i] = false;
        }
        return sum;
    }

}

int main() {

    int n;
    cin >> n >> s;

    arr = vector<int>(n+1, 0);
    isVisited = vector<bool>(n+1, false);

    for(int i=1; i<=n; i++) {   
        cin >> arr[i];
    }

    int sum=0;
    for(int i=1; i<=n; i++) {
        sum += getSubArrNum(0, 0, i);
    }
 
    cout << sum;
}