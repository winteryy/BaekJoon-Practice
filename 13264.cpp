#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> group;
int ind;

bool cmp(int i, int j){
    if(group[i] != group[j]){
        return group[i] < group[j];
    }else{
        return group[i+ind] < group[j+ind];
    }
}

vector<int> getSuffixArr(const string& s){
    int n = s.size();
    ind = 1;

    group.resize(n+1);
    group[n] = -1;

    for(int i=0; i<n; i++){
        group[i] = s[i];
    }

    vector<int> suffixArr(n);
    for(int i=0; i<n; i++){
        suffixArr[i] = i;
    }

    while(ind < n){
        sort(suffixArr.begin(), suffixArr.end(), cmp);

        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[suffixArr[0]] = 0;

        for(int i=1; i<n; i++){
            if(cmp(suffixArr[i-1], suffixArr[i])){
                newGroup[suffixArr[i]] = newGroup[suffixArr[i-1]]+1;
            }else{
                newGroup[suffixArr[i]] = newGroup[suffixArr[i-1]];
            }
        }
        group = newGroup;
        ind *= 2;
    }

    return suffixArr;
}

int main(){
    string s;
    cin >> s;
    vector<int> SA = getSuffixArr(s);

    for(int i=0; i<SA.size(); i++){
        cout << SA[i] << "\n";
    }
}