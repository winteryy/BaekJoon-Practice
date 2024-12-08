#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    auto cmp = [](const pair<pair<int, int>, int>& l, const pair<pair<int, int>, int>& r) {
        return l.second>r.second;
    };

    int ind = 1;
    while(t!=0) {
        vector<vector<int> > matrix(t, vector<int>(t));
        for(int i=0; i<t; i++) {
            for(int j=0; j<t; j++) {
                cin >> matrix[i][j];
            }
        }                
        vector<vector<int> > dist(t, vector<int>(t, INT32_MAX));
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >, decltype(cmp)> pq(cmp);
        pq.push({{0, 0}, matrix[0][0]});

        while(!pq.empty()) {
            auto pos = pq.top().first;
            int costSum = pq.top().second;
            pq.pop();

            if(dist[pos.first][pos.second]<=costSum) continue;
            if(pos.first==t-1 && pos.second==t-1) {
                cout << "Problem " << ind << ": " << costSum << "\n";
                break;
            }
            dist[pos.first][pos.second] = costSum;

            for(int i=0; i<4; i++) {
                int nextY = pos.first+dy[i];
                int nextX = pos.second+dx[i];

                if(nextY>=0 && nextY<t && nextX>=0 && nextX<t && dist[nextY][nextX]>costSum+matrix[nextY][nextX]) {
                    pq.push({{nextY, nextX}, costSum+matrix[nextY][nextX]});
                }
            }
        } 
        ind++;
        cin >> t;
    }
}   