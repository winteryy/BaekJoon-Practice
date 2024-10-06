#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int width = 2*n-1;

    vector<string> triangle(n, "");
    triangle[0] = "*";
    triangle[1] = "* *";
    triangle[2] = "*****";

    int refInd = 3;
    for(int i=3; i<n; i++) {
        if(i==refInd*2) refInd *= 2;
        triangle[i] += triangle[i%refInd];
        for(int j=0; j<2*(i+1)-1-(2*triangle[i%refInd].length()); j++) {
            triangle[i] += " ";
        }
        triangle[i] += triangle[i%refInd];
    }

    for(int i=0; i<n; i++) {
        string blank = "";
        for(int j=0; j<(width-triangle[i].length())/2; j++) {
            blank += " ";
        }
        cout << blank << triangle[i] << blank << "\n";
    }
}