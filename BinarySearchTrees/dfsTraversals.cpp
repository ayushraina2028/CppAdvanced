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

void preOrderTraversal(Node* root) {
    if(root == NULL) return;

    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
    if(root == NULL) return;

    
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if(root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    Node* a = new Node(10);
    Node* b = new Node(5);
    Node* c = new Node(15);
    Node* d = new Node(2);
    Node* e = new Node(8);
    Node* f = new Node(11);
    Node* g = new Node(19);


    // Connecting
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    // Display 
    // Preorder => [Root->Left->Right]
    preOrderTraversal(a);
    cout << endl;

    // Inorder Traversal => [Left->Root->Right]
    inOrderTraversal(a);
    cout << endl;
    // => See Inorder is sorted Array

    // Postorder Traversal => [Left->Right->Root]
    postOrderTraversal(a);
    cout << endl;

    // Time Complexity is O(n) and Space Complexity is O(height) ~ O(levels)
    // Call stack during recursion gets maximum size filled equal to levels in a tree.
    
    

}