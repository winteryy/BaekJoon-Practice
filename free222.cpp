#include <iostream>
#include <vector>

using namespace std;

int main() {
    int shipSpace, num, num2;
    string name;

    cin >> shipSpace >> num;

    vector<string> nameList;

    for(int i=0; i<num; i++) {
        cin >> name;
        nameList.push_back(name);
    }

    cin >> num;

    vector<string> moverList;
    for(int i=0; i<num; i++) {
        cin >> name;
        moverList.push_back(name);
    }

    cin >> num2;

    vector<vector<string> > cantLeaveComb;
    for(int i=0; i<num2; i++) {
        cin >> num;
        cantLeaveComb.push_back(vector<string>());
        for(int j=0; j<num; j++) {
            cin >> name;
            cantLeaveComb[i].push_back(name);
        }
    }

    cin >> num2;

    vector<vector<string> > cantBoardComb;
    for(int i=0; i<num2; i++) {
        cin >> num;
        cantBoardComb.push_back(vector<string>());
        for(int j=0; j<num; j++) {
            cin >> name;
            cantBoardComb[i].push_back(name);
        }
    }
    //¿ÏÀüÅ½»ö?
}