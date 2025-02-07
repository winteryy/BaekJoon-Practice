#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>

using namespace std;

class Node {
public:
    map<char, shared_ptr<Node> > children;

    Node() {
        children = map<char, shared_ptr<Node> >();
    }
    int dfs(int inputNum, bool isRoot) {
        int sum = 0;
        
        bool hasOnlyOne = children.size()==1;

        for(auto child: children) {
            if(child.first==' ') {
                sum += inputNum;
            } else {
                if(hasOnlyOne) {
                    sum += child.second->dfs((isRoot?1:0)+inputNum, false);
                } else {
                    sum += child.second->dfs(inputNum+1, false);
                }
            }
        }

        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cout<<fixed;
    cout.precision(2);
    while(cin >> n) {
        shared_ptr<Node> root = make_shared<Node>();
        
        string word;
        for(int i=0; i<n; i++) {
            cin >> word;
            shared_ptr<Node> cursor = root;
            
            for(char c: word) {
                if(cursor->children.find(c)!=cursor->children.end()) {
                    cursor = cursor->children[c];
                } else {
                    shared_ptr<Node> newChild = make_shared<Node>();
                    cursor->children.insert({c, newChild});
                    cursor = newChild;
                }
            }
            shared_ptr<Node> leaf = make_shared<Node>();
            cursor->children.insert({' ', leaf});
        }

        double result = (double)(root->dfs(0, true))/n;
        cout << result << "\n";
    }
}