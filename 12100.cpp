#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int calc(vector<vector<int> > matrix, int direction, int depth) {

    vector<vector<int> > newMatrix(matrix.size(), vector<int>(matrix.size(), 0));

    switch(direction) {
        case 0: {
            //right
            for(int i=0; i<matrix.size(); i++) {
                stack<pair<int, bool> > st; //num, mergeable
                for(int j=matrix.size()-1; j>=0; j--) {
                    if(matrix[i][j]==0) continue;
                    if(!st.empty()&&st.top().first==matrix[i][j]&&st.top().second) {
                        st.pop();
                        st.push({matrix[i][j]*2, false});
                    } else {
                        st.push({matrix[i][j], true});
                    }
                }

                stack<pair<int, bool> > newSt;
                while(!st.empty()) {
                    newSt.push(st.top());
                    st.pop();
                }

                for(int j=matrix.size()-1; j>=0; j--) {
                    if(newSt.empty()) break;
                    newMatrix[i][j] = newSt.top().first;
                    newSt.pop();
                }
            }

            break;
        }
        case 1: {
            //left
            for(int i=0; i<matrix.size(); i++) {
                stack<pair<int, bool> > st; //num, mergeable
                for(int j=0; j<matrix.size(); j++) {
                    if(matrix[i][j]==0) continue;
                    if(!st.empty()&&st.top().first==matrix[i][j]&&st.top().second) {
                        st.pop();
                        st.push({matrix[i][j]*2, false});
                    } else {
                        st.push({matrix[i][j], true});
                    }
                }

                stack<pair<int, bool> > newSt;
                while(!st.empty()) {
                    newSt.push(st.top());
                    st.pop();
                }

                for(int j=0; j<matrix.size(); j++) {
                    if(newSt.empty()) break;
                    newMatrix[i][j] = newSt.top().first;
                    newSt.pop();
                }
            }
            
            break;
        }
        case 2: {
            //up
            for(int i=0; i<matrix.size(); i++) {
                stack<pair<int, bool> > st; //num, mergeable
                for(int j=0; j<matrix.size(); j++) {
                    if(matrix[j][i]==0) continue;
                    if(!st.empty()&&st.top().first==matrix[j][i]&&st.top().second) {
                        st.pop();
                        st.push({matrix[j][i]*2, false});
                    } else {
                        st.push({matrix[j][i], true});
                    }
                }

                stack<pair<int, bool> > newSt;
                while(!st.empty()) {
                    newSt.push(st.top());
                    st.pop();
                }


                for(int j=0; j<matrix.size(); j++) {
                    if(newSt.empty()) break;
                    newMatrix[j][i] = newSt.top().first;
                    newSt.pop();
                }
            }

            break;
        }
        case 3: {
            //down
            for(int i=0; i<matrix.size(); i++) {
                stack<pair<int, bool> > st; //num, mergeable
                for(int j=matrix.size()-1; j>=0; j--) {
                    if(matrix[j][i]==0) continue;
                    if(!st.empty()&&st.top().first==matrix[j][i]&&st.top().second) {
                        st.pop();
                        st.push({matrix[j][i]*2, false});
                    } else {
                        st.push({matrix[j][i], true});
                    }
                }

                stack<pair<int, bool> > newSt;
                while(!st.empty()) {
                    newSt.push(st.top());
                    st.pop();
                }

                for(int j=matrix.size()-1; j>=0; j--) {
                    if(newSt.empty()) break;
                    newMatrix[j][i] = newSt.top().first;
                    newSt.pop();
                }
            }

            break;
        }
    }

    int largestNum = 0;

    if(depth == 5) {
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix.size(); j++) {
                largestNum = max(largestNum, newMatrix[i][j]);
            }
        }

        return largestNum;
    } else {
        for(int i=0; i<4; i++) {
            largestNum = max(largestNum, calc(newMatrix, i, depth+1));
        }

        return largestNum;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > matrix(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxNum = 0;
    for(int i=0; i<4; i++) {
        maxNum = max(maxNum, calc(matrix, i, 1));
    }
    
    cout << maxNum;

}