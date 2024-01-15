#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m; //n: people, m: parties
    cin >> n >> m;

    int know;
    cin >> know;
    queue<int> knowQ;

    vector<bool> peopleDirty(n+1, false);
    vector<bool> partyDirty(m+1, false);

    vector<vector<int> > people(n+1, vector<int>());
    vector<vector<int> > parties(m+1, vector<int>());
    
    for(int i=0; i<know; i++) {
        int knowNum;
        cin >> knowNum;
        peopleDirty[knowNum] = true;
        knowQ.push(knowNum);
    }

    for(int i=1; i<=m; i++) {
        int participantNum;
        cin >> participantNum;

        for(int j=0; j<participantNum; j++) {
            int participant;
            cin >> participant;
            people[participant].push_back(i);
            parties[i].push_back(participant);
        }
    }

    while(!knowQ.empty()) {
        int personNum = knowQ.front();
        knowQ.pop();

        for(int i=0; i<people[personNum].size(); i++) {
            int partyNum = people[personNum][i];
            if(!partyDirty[partyNum]) {
                for(int j=0; j<parties[partyNum].size(); j++) {
                    int checkPersonNum = parties[partyNum][j];
                    if(!peopleDirty[checkPersonNum]) {
                        peopleDirty[checkPersonNum] = true;
                        knowQ.push(checkPersonNum);
                    }
                }
                partyDirty[partyNum] = true;
            }
        }
    }

    int clearPartyNum = 0;
    for(int i=1; i<partyDirty.size(); i++) {
        if(!partyDirty[i]) {
            clearPartyNum++;
        }
    } 

    cout << clearPartyNum;
}