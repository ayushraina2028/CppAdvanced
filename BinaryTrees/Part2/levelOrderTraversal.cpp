#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
}; 

int calculateLevels(Node* root) {
    if(root == NULL) return 0;
    int levels = 1 + max(calculateLevels(root->left),calculateLevels(root->right));
    return levels;
}

void printNthLevel(Node* root, int curr_level, int level) {
    if(root==NULL) return;
    if(curr_level == level) {
        cout << root->val << " ";
        return; //  => because if u hve reached nth level then no need to make calls to further level.
    }
    printNthLevel(root->left, curr_level+1, level);
    printNthLevel(root->right, curr_level+1, level);
}

void levelOrderTraversal(Node* root) {
    int levels = calculateLevels(root);
    for(int i = 1;i <= levels;i++) {
        printNthLevel(root,1,i);
        cout << endl;   
    }
}


int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);


    // Connecting
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    levelOrderTraversal(a);
}

