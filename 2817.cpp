#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    double fivePercent = x*0.05;

    priority_queue<pair<double, char> > pq;
    vector<bool> qualified(26, false);
    char staff;
    double score;
    for(int i=0; i<n; i++) {
        cin >> staff >> score;
        if (score>=fivePercent) {
            qualified[staff-'A'] = true;
            for(int j=1; j<=14; j++) {
                pq.push(make_pair(score/j, staff));
            }
        }
    }

    vector<int> totalScore(26, 0);

    for(int i=0; i<14; i++) {
        if(pq.empty()){
            break;
        }
        totalScore[pq.top().second-'A']++;
        pq.pop();
    }

    for(int i=0; i<25; i++) {
        if(qualified[i]) {
            cout << (char)(i+'A') << " " << totalScore[i] << "\n";
        }
    }

}