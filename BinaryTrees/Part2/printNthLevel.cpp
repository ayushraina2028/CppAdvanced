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

void print(Node* root,int curr_level,int level) {
    if(root == NULL) return;
    
    // we tried by preorder, we can do by inOrder and post order also
    if(curr_level == level) {
        cout << root->val << " ";
    }
    print(root->left, curr_level+1, level);
    print(root->right, curr_level+1, level);
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

    print(a,1,3);
}

