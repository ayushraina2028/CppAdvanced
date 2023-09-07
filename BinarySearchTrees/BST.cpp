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

void displayBinarySearchTree(Node* root) {
    if(root == NULL) return;

    cout << root->val << " ";
    displayBinarySearchTree(root->left);
    displayBinarySearchTree(root->right);
}

int sumTreeNode(Node* root) {
    if(root == NULL) return 0;
    int ans = root->val + sumTreeNode(root->left) + sumTreeNode(root->right);
    return ans;
}

int sizeTreeNode(Node* root) {
    if(root == NULL) return 0;
    int size = 1 + sizeTreeNode(root->left) + sizeTreeNode(root->right); // Think, it is correct
    return size;
}

int maxValueInTreeNode(Node* root) {
    if(root==NULL) return INT_MIN; // dont return 0;
    int max1 = max(root->val,maxValueInTreeNode(root->left));
    int max2 = max(max1,maxValueInTreeNode(root->right));
    return max2;
}

int findLevelInBinarySearchTree(Node* root) {
    if(root == NULL) return 0;
    int levels = 1 + max(findLevelInBinarySearchTree(root->left), findLevelInBinarySearchTree(root->right));
    return levels;
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
    displayBinarySearchTree(a);
    cout << endl;

    // Sum
    int sum = sumTreeNode(a);
    cout << sum << endl;

    // Size
    int size = sizeTreeNode(a);
    cout << size << endl;
    
    // max value
    int maxVal = maxValueInTreeNode(a);
    cout << maxVal << endl;

    // Levels in Binary Tree
    int level = findLevelInBinarySearchTree(a);
    cout << level << endl;
} 