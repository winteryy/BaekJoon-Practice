#include <iostream>
#include <vector>
#include <stack>

using namespace std;

enum class Direction{
    HORIZONTAL, VERTICAL, DIAGONAL
};

struct Pipe {
    int y, x;
    Direction dir;
};

class Move {
public:
    pair<int, int> deltaNew; // {deltaY, deltaX}
    Direction dir;
    vector<pair<int, int> > validRange;

    Move(pair<int, int> deltaNew, Direction dir, vector<pair<int, int> >& validRange) {
        this->deltaNew = deltaNew;
        this->dir = dir;
        this->validRange = validRange;
    }
};

vector<pair<int, int> > horizontalRange = { {0, 1} };
vector<pair<int, int> > verticalRange = { {1, 0} };
vector<pair<int, int> > diagonalRange = { {0, 1}, {1, 1}, {1, 0} };

Move horizontalMove({0, 1}, Direction::HORIZONTAL, horizontalRange);
Move verticalMove({1, 0}, Direction::VERTICAL, verticalRange);
Move diagonalMove({1, 1}, Direction::DIAGONAL, diagonalRange);

vector<Move> horizontalMoveSet = { horizontalMove, diagonalMove };
vector<Move> verticalMoveSet = { verticalMove, diagonalMove };
vector<Move> diagonalMoveSet = { horizontalMove, verticalMove, diagonalMove };

int n;
bool matrix[17][17];

bool isValidRange(int y, int x) {
    return y>=1 && y<=n && x>=1 && x<=n && !matrix[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> matrix[i][j];
        }
    }

    stack<Pipe> st;
    st.push({1, 2, Direction::HORIZONTAL});
    int num = 0;

    while(!st.empty()) {
        auto top = st.top();
        st.pop();

        if(top.y==n && top.x==n) {
            num++;
            continue;
        }
        switch(top.dir) {
            case Direction::HORIZONTAL: {
                for(auto& move: horizontalMoveSet) {
                    int newY = top.y + move.deltaNew.first;
                    int newX = top.x + move.deltaNew.second;

                    bool isValid = true;
                    for(auto& delta: move.validRange) {
                        if(!isValidRange(top.y + delta.first, top.x + delta.second)) {
                            isValid = false;
                            break;
                        }
                    }

                    if(isValid) {
                        st.push({newY, newX, move.dir});
                    }
                }
                break;
            }

            case Direction::VERTICAL: {
                for(auto& move: verticalMoveSet) {
                    int newY = top.y + move.deltaNew.first;
                    int newX = top.x + move.deltaNew.second;

                    bool isValid = true;
                    for(auto& delta: move.validRange) {
                        if(!isValidRange(top.y + delta.first, top.x + delta.second)) {
                            isValid = false;
                            break;
                        }
                    }

                    if(isValid) {
                        st.push({newY, newX, move.dir});
                    }
                }
                break;
            }

            case Direction::DIAGONAL: {
                for(auto& move: diagonalMoveSet) {
                    int newY = top.y + move.deltaNew.first;
                    int newX = top.x + move.deltaNew.second;

                    bool isValid = true;
                    for(auto& delta: move.validRange) {
                        if(!isValidRange(top.y + delta.first, top.x + delta.second)) {
                            isValid = false;
                            break;
                        }
                    }

                    if(isValid) {
                        st.push({newY, newX, move.dir});
                    }
                }
            }
        }
    }

    cout << num;
}