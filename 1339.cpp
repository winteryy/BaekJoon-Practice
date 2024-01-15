#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Word {
public:
    vector<int> frequency;
    bool isUsed;

    Word() {
        frequency = vector<int>(8, 0);
        isUsed = false;
    }

    bool operator < (Word other) const {
        int thisSum = 0, otherSum = 0;
        for(int i=0; i<8; i++) {
            int multiNum = 1;
            for(int j=0; j<i; j++) {
                multiNum*=10;
            }

            thisSum+=multiNum*this->frequency[i];
            otherSum+=multiNum*other.frequency[i];
        }
        return thisSum < otherSum;
    }

};

int main() {
    int n;
    cin >> n;

    vector<string> words;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        words.push_back(s);
    }

    vector<Word> wordFreq(26, Word());

    for(int i=0; i<n; i++) {
        for(int j=words[i].size()-1; j>=0; j--) {
            wordFreq[words[i][j]-'A'].frequency[words[i].size()-1-j]++;
            wordFreq[words[i][j]-'A'].isUsed = true;
        }
    }

    priority_queue<Word> pq;
    for(auto w: wordFreq) {
        if(w.isUsed) {
            pq.push(w);
        }
    }

    int result = 0;
    int assignNum = 9;
    while(!pq.empty()) {
        for(int i=0; i<8; i++) {
            int multiNum = 1;
            for(int j=0; j<i; j++) {
                multiNum *= 10;
            }
            result += pq.top().frequency[i]*multiNum*assignNum;
        }
        pq.pop();
        assignNum--;
    }

    cout << result;
    
}