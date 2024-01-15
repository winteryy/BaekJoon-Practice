#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class StackEle{
public:
    int currentMoney;
    int currentFuel;
    bool isPromising;
    vector<int> currentRoute;
};

int main() {

    int n, k; //n:정점, k:연료량
    cin >> n >> k;
    int edgeNum;
    cin >> edgeNum;

    vector<vector<int> > costMatrix(n, vector<int>(n, -1));  //인덱스 0:A ~ 26: Z? , -1 경로 없
    for(int i=0; i<edgeNum; i++) {
        char town1;
        char town2;
        int cost;
        
        cin >> town1 >> town2 >> cost;
        costMatrix[town1-'A'][town2-'A'] = cost;
        costMatrix[town1-'A'][town2-'A'] = cost; //양방향 그래프? 사이클 여부?
    }

    bool goal = false;
    vector<pair<int, vector<int> > > answerList; //잔여연료, 경로

    stack<StackEle> st;
    StackEle stackEle;
    stackEle.currentMoney = 100;
    stackEle.currentFuel = k;
    stackEle.currentRoute.push_back(0);
    stackEle.isPromising = true;
    st.push(stackEle);

    vector<bool> isVisited(n, false);
    isVisited[0] = true;



    while(!st.empty()) {
        StackEle now = st.top();
        st.pop();
        int currentNode = now.currentRoute[now.currentRoute.size()-1];
        isVisited[currentNode] = true;

        if(currentNode == n-1) { //목적지 도착
            if(now.isPromising) {
                goal = true;
            }
            isVisited[currentNode] = false;
            answerList.push_back({now.currentFuel, now.currentRoute});
            continue;
        }

        bool isLeaf = true;
        for(int i=1; i<n; i++) {
            if(costMatrix[currentNode][i]!=-1 && !isVisited[i]) {
                isLeaf = false;
                StackEle newEle(now);
                if(now.currentFuel<costMatrix[currentNode][i]) {
                    newEle.isPromising = false;
                }
                newEle.currentFuel -= costMatrix[currentNode][i]-10;
                newEle.currentMoney += 200;
                newEle.currentRoute.push_back(i);
                st.push(newEle);
            }
        }
        if(isLeaf) {
            isVisited[currentNode] = false;
        }
    }

    int maxProfit = -1;

    for(int i=0; i<answerList.size(); i++) {
        bool valid = true;

        for(int j=0; j<answerList[i].second.size(); j++) {
            
        }
    }

    if(answerList.size()>1) {
        int check = answerList[0].first;
        for(int i=1; i<answerList.size(); i++) {
            if(check == answerList[i].first) {
                cout << "-1";
                return 0;
            }else {
                check = answerList[i].first;
            }
        }
    }

    for(int i=0; i<answerList.size(); i++) {
        for(int j=0; j<answerList[i].second.size(); j++) {
            cout << (char)(answerList[i].second[j]+'A') << " ";
        }
        cout << maxProfit << " " << answerList[i].first << "\n";
    }

	return 0;
}