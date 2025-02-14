#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

int c, n, q;

class Node {
public:
    map<char, Node*> children;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> n;
    
    Node* colorTrie = new Node();
    unordered_set<string> nicknameSet;
    int maxColorLen = 0;

    string input;
    for(int i=0; i<c; i++) {
        cin >> input;
        maxColorLen = max((size_t)maxColorLen, input.length());
        Node* cursor = colorTrie;

        for(char ch: input) {
            auto iter = cursor->children.find(ch);
            
            if(iter == cursor->children.end()) {
                Node* newNode = new Node();
                cursor->children.insert({ch, newNode});
                cursor = newNode;
            } else {
                cursor = (*iter).second;
            }
        }

        cursor->children.insert({' ', nullptr});
    }

    for(int i=0; i<n; i++) {
        cin >> input;
        nicknameSet.insert(input);
    }

    cin >> q;
    for(int i=0; i<q; i++) {
        cin >> input;

        Node* cursor = colorTrie;
        int indRange = min(maxColorLen, (int)input.size()-1);
        bool result = false;
        for(int i=0; i<indRange; i++) {
            auto iter = cursor->children.find(input[i]); // 현재 인덱스 문자 탐색
            if(iter != cursor->children.end()) { // 현재 인덱스 일치 문자 있으면
                cursor = (*iter).second;
                if(cursor->children.find(' ') != cursor->children.end()) { // 현재 인덱스 문자로 끝나는 색 있다면
                    if(nicknameSet.find(input.substr(i+1, input.size()-i-1)) != nicknameSet.end()) {
                        result = true;
                        break;
                    }
                }
            } else { // 일치하는 문자 없음
                break;
            }
        }

        cout << (result ? "Yes\n" : "No\n");
    }
}