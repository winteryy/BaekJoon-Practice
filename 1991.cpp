#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public: 
    char name;
    Node* lChild;
    Node* rChild;
    
    Node() {
        this->name = '.';
        this->lChild = nullptr;
        this->rChild = nullptr;
    }

    Node(char name) {
        this->name = name;
        this->lChild = nullptr;
        this->rChild = nullptr;
    }

    Node(char name, Node* lChild, Node* rChild) {
        this->name = name;
        this->lChild = lChild;
        this->rChild = rChild;
    }

    void preorderTraversal() {
        cout << name;
        if(lChild!=nullptr) {
            lChild->preorderTraversal();
        }
        if(rChild!=nullptr) {
            rChild->preorderTraversal();
        }
    }

    void inorderTraversal() {
        if(lChild!=nullptr) {
            lChild->inorderTraversal();
        }
        cout << name;
        if(rChild!=nullptr) {
            rChild->inorderTraversal();
        }
    }

    void postorderTraversal() {
        if(lChild!=nullptr) {
            lChild->postorderTraversal();
        }
        if(rChild!=nullptr) {
            rChild->postorderTraversal();
        }
        cout << name;
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<char, char> > tempNodeList(26);

    char name, lChild, rChild;
    for(int i=0; i<n; i++) {   
        cin >> name >> lChild >> rChild;
        tempNodeList[name-'A'] = {lChild, rChild};
    }

    queue<Node*> q;
    Node root = Node('A');
    q.push(&root);

    while(!q.empty()) {
        Node* curNode = q.front();
        q.pop();

        if(tempNodeList[curNode->name-'A'].first!='.') {
            Node* lChild = new Node(tempNodeList[curNode->name-'A'].first);
            curNode->lChild = lChild;
            q.push(lChild);
        }
        if(tempNodeList[curNode->name-'A'].second!='.') {
            Node* rChild = new Node(tempNodeList[curNode->name-'A'].second);
            curNode->rChild = rChild;
            q.push(rChild);
        }    
    }

    root.preorderTraversal();
    cout << "\n";
    root.inorderTraversal();
    cout << "\n";
    root.postorderTraversal();
}