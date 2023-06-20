#include <iostream>
#include <vector>

using namespace std;

int sudoku[9][9] = {0,};
int answer = false;
int answerBoard[9][9] = {0,};

bool isPromising(int y, int x){
    for(int i=0; i<9; i++){
        if(i!=x&&sudoku[y][i]==sudoku[y][x]){
            return false;
        }
    }
    for(int i=0; i<9; i++){
        if(i!=y&&sudoku[i][x]==sudoku[y][x]){
            return false;
        }
    }
    for(int i=0; i<3; i++){
        int newY = y+i;
        if((y+i)/3 != y/3){
            newY -= 3;
        }
        for(int j=0; j<3; j++){
            int newX = x+j;
            if((x+j)/3 != x/3){
                newX -= 3;
            }
            if(i+j!=0){
                if(sudoku[newY][newX] == sudoku[y][x]){
                    return false;
                }
            }
        }
    }

    return true;    
}

void BT(int ind, vector<pair<int, int> > &blank){
    if(answer){
        return;
    }
    if(ind==-1){
        for(int i=1; i<10; i++){
            sudoku[blank[0].first][blank[0].second] = i;
            BT(ind+1, blank);
        }        
    }else if(isPromising(blank[ind].first, blank[ind].second)){
        if(ind==blank.size()-1){
            if(answer == false){
                for(int i=0; i<9; i++){
                    for(int j=0; j<9; j++){
                        answerBoard[i][j] = sudoku[i][j];
                    }
                }
                answer = true;
            }

        }else{
            for(int i=1; i<10; i++){
                sudoku[blank[ind+1].first][blank[ind+1].second] = i;
                BT(ind+1, blank);
            }
            sudoku[blank[ind+1].first][blank[ind+1].second] = 0;
        }
    }else{
        sudoku[blank[ind].first][blank[ind].second] = 0;
    }
}

int main(){
    vector<pair<int, int> > blank;
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j]==0){
                blank.push_back(make_pair(i, j));
            }
        }
    }

    BT(-1, blank);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << answerBoard[i][j] << " ";
        }
        cout << "\n";
    }
}