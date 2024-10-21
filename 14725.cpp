#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
    string food;
    map<string, Node*> children;

    Node(string food) {
        this->food = food;
        children = map<string, Node*>();
    }

    void traversal(int depth) {
        for(int i=0; i<depth; i++) {
            cout << "--";
        }
        cout << food << "\n";

        for(auto child: children) {
            child.second->traversal(depth+1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, depth;
    string food;

    cin >> n;

    Node root = Node("root");

    for(int i=0; i<n; i++) {
        cin >> depth;

        Node* curNode = &root;
        for(int k=0; k<depth; k++) {
            cin >> food;
            auto iter = curNode->children.find(food);
            if(iter==curNode->children.end()) {
                Node* newNode = new Node(food);
                curNode->children.insert({food, newNode});
                curNode = newNode;
            } else {
                curNode = iter->second;
            }
        }
    }

    for(auto child: root.children) {
        child.second->traversal(0);
    }
}