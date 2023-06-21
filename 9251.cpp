#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int size1 = s1.size();
    int size2 = s2.size();

    vector<vector<int> > lcs(size1+1, vector<int>(size2+1, 0));

    for(int i=1; i<=size1; i++){
        for(int j=1; j<=size2; j++){
            if(s1[i-1] == s2[j-1]){
                lcs[i][j] = lcs[i-1][j-1]+1;
            }else{
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }

    cout << lcs[size1][size2];
}