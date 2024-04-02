#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int> > dp(s1.size()+1, vector<int>(s2.size()+1, 0));
}