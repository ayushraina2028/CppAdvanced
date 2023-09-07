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

int main() {
    Node* a = new Node(50);
    Node* b = new Node(30);
    Node* c = new Node(70);
    Node* d = new Node(20);
    Node* e = new Node(40);
    Node* f = new Node(60);
    Node* g = new Node(80);


    // Connecting
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    // InOrder Predecessor => take one left and right till you find null
    // InOrder Sucessor => take one right and left till you find null.
}