#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int matrix[1000][1000];
bool isVisited[1000][1000];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
 
    string input;
    for(int i=0; i<n; i++) {
        cin >> input;
        for(int j=0; j<m; j++) {
            if(input[j]=='0') {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = -1;
            }
        }
    }

    vector<int> areaSet;
    areaSet.push_back(0); //dummy
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j]==0) {
                queue<pair<int, int> > q;
                
                q.push({i, j});
                areaSet.push_back(0);
                int setInd = areaSet.size()-1;
                while(!q.empty()) {
                    auto point = q.front();
                    q.pop();
                    if(matrix[point.first][point.second]!=0) continue;
                    areaSet[setInd]++;
                    matrix[point.first][point.second] = setInd;

                    for(int k=0; k<4; k++) {
                        int newY = point.first+dy[k];
                        int newX = point.second+dx[k];

                        if(newY>=0 && newY<n && newX>=0 && newX<m && matrix[newY][newX]==0) {
                            q.push({newY, newX});
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j]==-1) {
                int sum = 0;
                int consumedNumList[4]={0,0,0,0};

                for(int k=0; k<4; k++) {
                    int newY = i+dy[k];
                    int newX = j+dx[k];

                    if(newY>=0 && newY<n && newX>=0 && newX<m && matrix[newY][newX]!=-1) {
                        bool consumedFlag = false;
                        for(auto consumedNum: consumedNumList) {
                            if(consumedNum==matrix[newY][newX]) {
                                consumedFlag = true;
                                break;
                            }
                        }
                        if(!consumedFlag) {
                            sum += areaSet[matrix[newY][newX]];
                            consumedNumList[k] = matrix[newY][newX];
                        }
                    }
                }
                cout << (sum+1)%10;
            } else {
                cout << "0";
            }
        }

        cout << "\n";
    }
}