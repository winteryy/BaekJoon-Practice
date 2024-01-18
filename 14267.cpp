#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> getScore;
vector<int> finalScore;

int getFinalScore(int n) {
    if(finalScore[n]==-1) {
        if(parent[n]!=-1) {
            finalScore[n] = getScore[n]+getFinalScore(parent[n]);
        }else {
            finalScore[n] = 0;
        }
    }

    return finalScore[n];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    parent = vector<int>(n+1);
    getScore = vector<int>(n+1, 0);
    finalScore = vector<int>(n+1, -1);
    for(int i=1; i<=n; i++) {
        cin >> parent[i];
    }

    for(int i=0; i<m; i++) {
        int num, w;
        cin >> num >> w;
        getScore[num] += w;
    }

    for(int i=1; i<=n; i++) {
        cout << getFinalScore(i) << " ";
    }
    
}